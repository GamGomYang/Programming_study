import pandas as pd
from sklearn.preprocessing import LabelEncoder, RobustScaler
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import f1_score

train = pd.read_csv("creditcard_train.csv")
test = pd.read_csv("creditcard_test.csv")

freq = train['OCCUPATION_TYPE'].mode()[0]
train['OCCUPATION_TYPE'] = train['OCCUPATION_TYPE'].fillna(freq)
test['OCCUPATION_TYPE'] = test['OCCUPATION_TYPE'].fillna(freq)

target = train.pop('STATUS')

train = train.drop('ID', axis=1)
test = test.drop('ID', axis=1)

cols = train.select_dtypes(include='object').columns
for col in cols:
    le = LabelEncoder()
    train[col] = le.fit_transform(train[col])
    test[col] = le.transform(test[col])

scaler = RobustScaler()
num_cols = train.select_dtypes(exclude='object').columns
train[num_cols] = scaler.fit_transform(train[num_cols])
test[num_cols] = scaler.transform(test[num_cols])

X_tr, X_val, y_tr, y_val = train_test_split(train, target, test_size=0.2, random_state=0)

rf = RandomForestClassifier(n_estimators=500, class_weight='balanced', random_state=0)
rf.fit(X_tr, y_tr)

pred = rf.predict(X_val)
score = f1_score(y_val, pred)
print("F1:", score)

pred = rf.predict(test)
submit = pd.DataFrame({'pred': pred})
submit.to_csv("result.csv", index=False)
