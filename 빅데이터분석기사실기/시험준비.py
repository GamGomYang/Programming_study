train = pd.read_csv('train.csv')
test= pd.read_csv('test.csv')

 # 1. 데이터 확인하기 

import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier # ☆분류
from sklearn.ensemble import RandomForestRegressor # ★회귀
from sklearn.metrics import f1_score, accuracy_score, roc_auc_score # ☆분류
from sklearn.metrics import r2_score, mean_absolute_error, mean_squared_error # ★회귀

print(train) # 변수 및 데이터 확인
print(test)
print(train.info()) # 범주형 변수 확인
print(test.info())
print(train.isnull().sum()) # 결측치 확인
print(test.isnull().sum())

# 2. 데이터 전처리 - train, test 둘 다 처리! (→ But, 보통 결측치 없는 데이터로 출제됨) 
train['A'] = train['A'].fillna(train['A'].mean()) # 평균 대체

test['A'] = test['A'].fillna(test['A'].mean()) 
train['A'] = train['A'].fillna(train['A'].mode()[0]) # 최빈값 대체

train['A'] = train['A'].fillna(0) # 0으로 대체
train['A'] = train['A'].fillna(method='bfill') # 뒤 값으로 대체

 
train = train.dropna() # 전체 결측치 데이터 삭제
train = train.dropna(subset=['A', 'B']) # 특정컬럼의 결측치 데이터 삭제
train = train.dropna(axis=1) # 결측치 있는 컬럼 삭제

# 3. 불필요한 데이터 삭제
test_id = test['ID'] # ID를 최종 제출파일에 포함하여야 하는 경우에 실행
y = train['price'] # 예측 대상
train = train.drop(['ID', 'name'], axis=1) # 데이터와 관련 없는 변수 작성
test = test.drop(['ID', 'name'], axis=1)

# 4. 원핫인코딩
df = pd.concat([train, test]) # 합치기
df = pd.get_dummies(df, columns=['A', 'B']) # 범주형 변수 모두 작성 / 더미변환
train = df.iloc[:len(train),:].copy() # 다시 분리
test = df.iloc[len(train):,:].copy()

# 5. 검증데이터 분리
x_tr, x_val, y_tr, y_val = train_test_split(train, y, test_size=0.2, random_state=42)

# 6. 모델 학습 및 평가 (랜덤포레스트)
rf = RandomForestClassifier(random_state=42) # ☆분류

rf = RandomForestRegressor(random_state=42) # ★회귀
rf.fit(x_tr, y_tr)

# ☆7-1. 분류모델 평가 및 예측 - 1) 정확도, 직접예측 (사용자 수 등)
pred = rf.predict(x_val)
print(f1_score(y_val, pred)) # 다중분류는 (y_val, pred, average='macro') 작성
print(accuracy_score(y_val, pred))
pred = rf.predict(test)
pd.DataFrame({'ID':test_id, 'pred':pred}).to_csv('result.csv', index=False) # 제출해야 하는 변수명으로 작성자세히 알아보기pandas라이브러리자료분석데이터분석파이썬Pandas데이터분석가빅 데이터빅데이터빅데이터 분석기사

# ☆7-1. 분류모델 평가 및 예측 - 2) auc, 확률
pred_proba = rf.predict_proba(x_val)[:,1]
print(roc_auc_score(y_val, pred_proba))
pred_proba = rf.predict_proba(test)[:,1]
pd.DataFrame({'Id':test_id, 'pred':pred_proba}).to_csv('result.csv', index=False)

# ★7-2. 회귀모델 평가 및 예측
pred = rf.predict(x_val)
print("r2: ",r2_score(y_val, pred)) # R-squared (1에 가까울수록 좋음)
print("mae: ",mean_absolute_error(y_val, pred)) # MAE
print("mse: ",mean_squared_error(y_val, pred)) # MSE
print("rmse: ",np.sqrt(mean_squared_error(y_val, pred))) # RMSE (자주 출제됨)
pred = rf.predict(test)
pd.DataFrame({'ID':test_id, 'pred':pred}).to_csv("result.csv", index=False)
 
 # 8. 결과 확인
 print(len(pred), len(test_id)) # 동일해야 함
result = pd.read_csv('result.csv') # 예시 형태로 나오는지 확인
print(result)


# 데이터 확인하기
print( df.head() ) # 앞 5줄 추출
print( df.shape ) # 행열 개수 추출
print( df.info() ) # 컬럼 정보
print( df.describe() ) # 기초 통계 정보 (수치형)
print( df.describe(include='object') ) # 기초 통계 정보 (범주형)
print( df.describe(include='all') ) # 기초 통계 정보 (모두)
print( df.count() ) # 열별(컬럼) 데이터 개수, 결측치 제외자세히 알아보기조건 필터링데이터 과학 컨설팅머신러닝 입문 서적분석 컨설팅파이썬 프로그래밍데이터베이스 관리 시스템Pandas빅 데이터빅데이터 컨설팅자료 분석 솔루션
print( df.count(axis=1) ) # 행별 데이터 개수, 결측치 제외
print( df.nunique() ) # 항목 종류 수
print( df['지역'].nunique() ) # 항목 종류
print( df['지역'].value_counts() ) # 항목별 개수
print( df['나이'].max() ) # 최대값
print( df.T.sum() ) # 행렬변환, 행 단위로 합하기
 
 # 그룹별 통계
df.groupby(['지역', '성별'])['나이'].mean() # 지역 및 성별 평균 나이
df.groupby(['지역', '성별']).mean().reset_index() # 인덱스 형태로 리셋
df['나이'].quantile(0.25) # 하위 25% 값

 # 조건 필터링
a = df['지역'] == '서울특별시'
b = df['나이'] < 30
df[a & b] # 해당 조건 조회
len(df[a & b]) # 해당 조건 데이터 개수

a = df['continent'] == 'Europe' # 유럽 데이터만 저장
df = df[a]



# 정렬
df.sort_index(ascending=False) # 인덱스 기준 내림차순
df.sort_values(['지역', '성별'], ascending=[False, True]) # 지역 내림차순, 성별 오름차순
# 중복값 제거
df = df.drop_duplicates() # 중복값 제거
df = df.drop_duplicates(subset=['지역', '성별'], keep='last') # 특정 컬럼만 중복값 제거 (last는 뒤에 값을 살림)

# 인덱싱자세히 알아보기빅 데이터데이터 정렬 도구자료 분석 솔루션파이썬 프로그래밍 강좌머신러닝 입문 서적numpy넘파이데이터 웨어하우징 플랫폼SQL 데이터베이스 학습데이터 시각화 도구
df.loc[0] # loc[인덱스 명] → ID 이름이 0인 데이터 출력
df.iloc[0] # iloc[인덱스 번호] → 0번째줄 데이터 출력
df.iloc[:3] # 상위 3개 데이터 출력
df[:int(len(df)*0.7)] # 상위 70% 데이터 출력

# 슬라이싱
df.loc[:,'지역':'성별'] # loc[인덱스 명, 컬럼 명], 마지막 포함O → 지역~성별 컬럼의 모든 데이터 출력
df.iloc[0:3:,0:1] # iloc[인덱스 번호, 컬럼 번호], 마지막 포함X → 0번째 컬럼의 0~2번째 데이터 출력
df['지역'].str[:2] # 앞 두글자 추출 → 강원, 경기, 서울, 인천...
df['지역'][:2] # 두 개 데이터 추출 → 강원특별자치도, 경기도

# 데이터 나누기
df['음료'].str.split() # 띄어쓰기 기준으로 단어 나누기 → 블루베리, 에이드
df['음료'].str.split().str[0] # 첫번째 값만 추출 → 블루베리

# 데이터 찾기
df['음료'].str.contains('딸기') # 일부 단어 찾기 O → False True False...
df.isin(['블루베리 에이드', '딸기 에이드']) # 일부 단어 찾기 X → True, True, False...

# 날짜 형식 변환
pd.to_datetime(df['date'])
 df['date'].dt.year # year 값만 분리 (month, day, hour, minute, second도 가능)
 df['day'] = df['date'].dt.day_name() # 요일 값을 day 컬럼에 저장

df[df['day'] == 'Sunday']['categoryId'].value_counts().index[0] # 일요일에 가장 많은 categoryId
