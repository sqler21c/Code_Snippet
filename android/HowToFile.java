
/*
내부 저장소에 파일 저장
내부 저장소에 파일을 저장할 경우, 다음 두 메서드 중 하나를 호출하여
적합한 디렉터리를 File로 얻을 수 있습니다.

getFilesDir()
앱에 대한 내부 디렉터리를 나타내는 File을 반환합니다.
getCacheDir()
앱의 임시 캐시 파일에 대한 내부 디렉터리를 나타내는 File을 반환합니다.
더 이상 필요하지 않은 파일은 모두 삭제하고 언제든지 사용할 수 있는
메모리 크기에 합리적인 크기 제한(예. 1MB)을 구현해야 합니다. 
저장 공간이 부족해지기 시작하면 경고 없이 시스템이 캐시 파일을 삭제할 수도 있습니다.
이러한 디렉터리 중 하나에서 새 파일을 생성하려면 File() 생성자를 사용하고
내부 저장소 디렉터리를 지정하는 상기 메서드 중 하나를 통해 제공되는 File을 전달하면 됩니다. 예:
*/
File file = new File(context.getFilesDir(), filename);
//또한, openFileOutput()을 호출하여 내부 디렉터리의 파일에 데이터를 쓰는
//FileOutputStream을 가져올 수도 있습니다. 다음 예는 몇몇 텍스트를 파일에 쓰는 방법을 보여줍니다.
String filename = "myfile";
String string = "Hello world!";
FileOutputStream outputStream;

try {
  outputStream = openFileOutput(filename, Context.MODE_PRIVATE);
  outputStream.write(string.getBytes());
  outputStream.close();
} catch (Exception e) {
  e.printStackTrace();
}

/*
또는 파일을 캐싱해야 할 경우 createTempFile()을 대신 사용합니다.
예를 들어 다음 메서드는 URL에서 파일 이름을 추출한 후 해당 이름을
사용하여 앱의 내부 캐시 디렉터리에 파일을 생성합니다.
*/
public File getTempFile(Context context, String url) {
    File file;
    try {
        String fileName = Uri.parse(url).getLastPathSegment();
        file = File.createTempFile(fileName, null, context.getCacheDir());
    } catch (IOException e) {
        // Error while creating file
    }
    return file;
}
/*
참고: 앱의 내부 저장소 디렉터리는 Android 파일 시스템의 특별한 위치에 있는
앱의 패키지 이름으로 지정됩니다. 엄밀히 말하면, 파일 모드를 읽기 가능으로
설정할 경우 다른 앱이 내부 파일을 읽을 수 있습니다. 하지만 이는 다른 앱도
여러분 자신의 앱 패키지 이름 및 파일 이름을 알아야 가능합니다. 다른 앱은
여러분 자신의 내부 디렉터리를 탐색할 수 없으며 명시적으로 읽기 가능 및 쓰기
가능으로 파일을 설정하지 않으면 파일을 읽거나 쓸 수 없습니다.
따라서 MODE_PRIVATE을 내부 저장소 내 파일에 사용하는 한,
다른 앱이 이러한 파일에 액세스할 수 없습니다
*/


외부 저장소에 파일 저장
사용자가 외부 저장소를 PC에 마운트했거나 외부 저장소를 제공하는 SD 카드를 제거한 경우 등에는 외부 저장소를 사용할 수 없기 때문에 액세스하기 전 항상 볼륨이 사용 가능한지 확인해야 합니다. getExternalStorageState()를 호출하여 외부 저장소 상태를 쿼리할 수 있습니다. 반환된 상태가 MEDIA_MOUNTED와 동일하다면 파일을 읽거나 파일에 쓸 수 있습니다. 예를 들어 다음 메서드는 저장소의 가용성을 확인하는 데 유용합니다.

/* Checks if external storage is available for read and write */
public boolean isExternalStorageWritable() {
    String state = Environment.getExternalStorageState();
    if (Environment.MEDIA_MOUNTED.equals(state)) {
        return true;
    }
    return false;
}

/* Checks if external storage is available to at least read */
public boolean isExternalStorageReadable() {
    String state = Environment.getExternalStorageState();
    if (Environment.MEDIA_MOUNTED.equals(state) ||
        Environment.MEDIA_MOUNTED_READ_ONLY.equals(state)) {
        return true;
    }
    return false;
}

외부 저장소는 사용자 및 다른 앱에 의해 수정될 수 있으나, 여기에 저장할 수 있는 파일로는 두 가지 범주가 있습니다.

공용 파일
다른 앱 및 사용자가 자유롭게 사용할 수 있는 파일입니다. 사용자가 앱을 제거해도 이러한 파일을 사용자가 계속 사용할 수 있도록 유지해야 합니다.
예를 들어 앱으로 캡처된 사진 또는 기타 다운로드된 파일이 이에 해당합니다.

전용 파일
정당하게 앱에 속하고 사용자가 앱을 제거 하면 삭제되어야 하는 파일입니다. 이러한 파일은 외부 저장소에 저장된 파일이기 때문에 엄밀히 말해 사용자 및 다른 앱의 액세스가 가능하긴 하지만, 앱 외부에서 사용자에게 실제로 가치를 제공하지는 않습니다. 사용자가 앱을 제거하면 시스템은 앱의 외부 전용 디렉터리 내 모든 파일을 삭제합니다.
예를 들어 앱에서 다운로드한 추가 리소스 또는 임시 미디어 파일이 이에 해당합니다.

외부 저장소에 공용 파일을 저장하려는 경우 getExternalStoragePublicDirectory() 메서드를 사용하여 외부 저장소에 적절한 디렉터리를 나타내는 File을 가져옵니다. 이 메서드는 DIRECTORY_MUSIC 또는 DIRECTORY_PICTURES와 같은 다른 공개 파일과 논리적으로 구성될 수 있도록 저장하고자 하는 파일의 유형을 지정하는 인수를 받습니다. 예:

public File getAlbumStorageDir(String albumName) {
    // Get the directory for the user's public pictures directory.
    File file = new File(Environment.getExternalStoragePublicDirectory(
            Environment.DIRECTORY_PICTURES), albumName);
    if (!file.mkdirs()) {
        Log.e(LOG_TAG, "Directory not created");
    }
    return file;
}
개인 파일을 앱에 저장하고자 하는 경우, getExternalFilesDir()을 호출하고 원하는 디렉터리 유형을 나타내는 이름을 전달하여 적절한 디렉터리를 얻을 수 있습니다. 이런 식으로 생성된 각 디렉터리는 부모 디렉터리에 추가됩니다. 이 디렉터리는 사용자가 앱을 제거할 때 시스템이 삭제하는 앱의 모든 외부 저장소 파일을 캡슐화합니다.

예를 들어, 다음은 개인 사진 앨범을 위한 디렉터리 생성 시 사용 가능한 메서드입니다.

public File getAlbumStorageDir(Context context, String albumName) {
    // Get the directory for the app's private pictures directory.
    File file = new File(context.getExternalFilesDir(
            Environment.DIRECTORY_PICTURES), albumName);
    if (!file.mkdirs()) {
        Log.e(LOG_TAG, "Directory not created");
    }
    return file;
}
미리 정의된 하위 디렉터리 이름 중 파일에 알맞은 이름이 없을 경우 대신 getExternalFilesDir()을 호출하고 null을 전달할 수 있습니다. 그러면 앱의 외부 저장소 내 전용 디렉터리의 루트 디렉터리가 반환됩니다.

사용자가 앱을 제거할 때 getExternalFilesDir()이 삭제된 디렉터리 내에 디렉터리를 생성한다는 것을 기억하세요. 앱이 카메라이고 사용자가 사진을 계속 간직하고자 하는 경우처럼, 사용자가 앱을 제거한 후에도 본인이 저장하는 파일을 사용 가능하게 유지해야 하는 경우 getExternalStoragePublicDirectory()를 대신 사용해야 합니다.

공유 파일에 getExternalStoragePublicDirectory()를 사용하든 개인 파일에 getExternalFilesDir()을 사용하든지에 관계없이 DIRECTORY_PICTURES와 같이 API 상수로 제공되는 디렉터리 이름을 사용해야 합니다. 이러한 디렉터리 이름은 시스템이 파일을 적절하게 처리할 수 있게 해줍니다. 예를 들어, DIRECTORY_RINGTONES에 저장된 파일은 시스템 미디어 스캐너에 의해 음악 대신 벨소리로 분류됩니다.

여유 공간 쿼리
저장하는 데이터의 크기를 미리 알고 있을 경우, getFreeSpace() 또는 getTotalSpace()를 호출하여 IOException을 초래하지 않고 사용 공간이 충분한지 확인할 수 있습니다. 이러한 메서드는 각각 저장소 볼륨에서 현재 사용 가능한 공간 및 전체 공간을 알려줍니다. 이 정보는 일정 임계치를 초과하는 수준으로 저장소 볼륨이 차는 것을 방지하는 데도 유용합니다.

하지만 시스템은 getFreeSpace()로 지정된 만큼의 바이트를 쓸 수 있다고 보장하지 않습니다. 저장하고자 하는 데이터의 크기보다 반환된 숫자가 몇 MB 더 클 경우 또는 파일 시스템이 90% 미만으로 찼을 경우 안심하고 작업을 진행할 수 있습니다. 그렇지 않다면 저장소에 데이터를 쓰지 않는 것이 좋습니다.

참고: 파일을 저장하기 전에 사용 가능한 공간을 꼭 확인할 필요는 없습니다. 대신, 파일을 곧바로 쓴 후 IOException이 발생하는 경우 이를 캐치하면 됩니다. 필요한 공간을 정확히 모르는 경우 이러한 방법을 사용할 수 있습니다. 예를 들어 파일을 저장하기 전에 PNG 이미지를 JPEG로 변환하여 파일 인코딩을 변경하는 경우, 파일의 크기를 사전에 알 수 없습니다.

파일 삭제
더 이상 필요하지 않은 파일은 항상 삭제해야 합니다. 파일을 삭제하는 가장 간단한 방법은 열린 파일 참조가 delete()를 직접 호출하도록 하는 것입니다.

myFile.delete();
파일이 내부 저장소에 저장되어 있는 경우, Context에 위치를 요청하고 deleteFile()을 호출하여 파일을 삭제할 수도 있습니다.

myContext.deleteFile(fileName);
참고: 사용자가 앱을 제거하면 Android 시스템이 다음 항목을 삭제합니다.
내부 저장소에 저장한 모든 파일
getExternalFilesDir()을 사용해 외부 저장소에 저장한 모든 파일
하지만 getCacheDir()로 생성된 모든 캐시 파일과 더 이상 필요치 않은 다른 파일은 정기적으로 직접 삭제해야 합니다.
