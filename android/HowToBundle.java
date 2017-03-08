

Bundle extras = new Bundle();
extras.putSerializable("aa", Object);
intent.putExtras(extras);
...

Object y = getIntent().getExtras().get("aa");

===========================================
1	Vector<LOGINDATA> vvv = new Vector<LOGINDATA>();
2	Intent intent = new Intent();
3	intent.putExtra("key", vvv);


//백터가 컬랙션이기 때문에 직렬화가 가능해서 위와같이 넣고 받아서 뺄때는 아래와 같이 하면 되요. ^^


Vector<LOGINDATA> rrr = (Vector<LOGINDATA>)intent.getExtras().getSerializable("key");
