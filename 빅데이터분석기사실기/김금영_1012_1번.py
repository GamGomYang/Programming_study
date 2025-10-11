import pandas as pd
from sklearn.preprocessing import MinMaxScaler
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import roc_auc_score

train = pd.read_csv("diabetes_train.csv")
test = pd.read_csv("diabetes_test.csv")

target = train.pop('Outcome')

scaler = MinMaxScaler()
train = scaler.fit_transform(train)
test = scaler.transform(test)

X_tr, X_val, y_tr, y_val = train_test_split(train, target, test_size=0.2, random_state=0)

rf = RandomForestClassifier(max_depth=5, n_estimators=500, random_state=0)
rf.fit(X_tr, y_tr)
pred = rf.predict_proba(X_val)
roc_auc = roc_auc_score(y_val, pred[:, 1])
print("ROC-AUC:", roc_auc)

pred = rf.predict_proba(test)
submit = pd.DataFrame({'pred': pred[:, 1]})
submit.to_csv("result.csv", index=False)
