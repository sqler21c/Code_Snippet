
/*
SharedPreferences에 쓰기
공유 기본 설정 파일에 데이터를 쓰려면 SharedPreferences에서 edit()를 호출하여 SharedPreferences.Editor를 생성해야 합니다.

putInt() 및 putString()과 같은 메서드를 사용하여 쓰고자 하는 키와 값을 전달합니다. 그런 다음, commit()을 호출하여 변경 내용을 저장합니다. 예:
*/
SharedPreferences sharedPref = getActivity().getPreferences(Context.MODE_PRIVATE);
SharedPreferences.Editor editor = sharedPref.edit();
editor.putInt(getString(R.string.saved_high_score), newHighScore);
editor.commit();

/*
SharedPreferences에서 읽어오기
공유 기본 설정 파일에서 값을 검색하려면 원하는 값에 대한 키를 제공하고 선택 사항으로 키가 없을 경우 반환할 기본값을 제공하여 getInt() 및 getString()과 같은 메서드를 호출해야 합니다. 예:
*/
SharedPreferences sharedPref = getActivity().getPreferences(Context.MODE_PRIVATE);
int defaultValue = getResources().getInteger(R.string.saved_high_score_default);
long highScore = sharedPref.getInt(getString(R.string.saved_high_score), defaultValue);
