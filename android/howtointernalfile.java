
//내부 저장

                try {
                    FileOutputStream fos = openFileOutput
                            ("myfile.txt", // 파일명 지정
                                    Context.MODE_APPEND);// 저장모드
                    PrintWriter out = new PrintWriter(fos); //string으로
                    out.println(data);
                    out.close();
                } catch (Exception e) {
                    e.printStackTrace();
                }
출처: http://bitsoul.tistory.com/116 [Happy Programmer~]

            try{
                /*
                openFileOutput()을 호출하여 내부 디렉터리의 파일에 데이터를 쓰는
                FileOutputStream을 가져올 수도 있습니다.
                */
                FileOutputStream outputStream= openFileOutput(fileName, Context.MODE_PRIVATE);
                //outputStream.write(string.getBytes());
                outputStream.write(editText.getText().toString().getBytes());
                outputStream.close();
            }catch(Exception e){
                e.printStackTrace();
            }



//일기
              FileInputStream inputStream = openFileInput(fileName);
              InputStreamReader inputStreamReader = new InputStreamReader(inputStream);
              BufferedReader bufferedReader = new BufferedReader(inputStreamReader);
              StringBuilder sb = new StringBuilder();

              String line ;
               while ((line = bufferedReader.readLine()) != null) {
                   sb.append(line);
               }
               inputStream.close();
           } catch (Exception e) {
               e.printStackTrace();
           }
