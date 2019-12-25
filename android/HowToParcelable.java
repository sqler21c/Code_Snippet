/*
앱을 만들다 보면 인텐트를 통해 단순히 String, int, boolean 같은 기본 타입 뿐 아니고
커스텀 클래스나 오브젝트를 다른 컴포넌트에 전달해 줘야 할 경우가 많다.
그 경우 단순히 그냥 인텐트에 putExtra() 로는  넣어줄 수가 없다.
안드로이드에서는 그런 경우를 위해 자바의 Serialization 개념과
유사한 Parcelable이라는 클래스가 있다.

먼저 이런것이 왜 필요한가 살펴보겠다. 예를 들어 다음과 같은 클래스가 있다고 하자.
*/

public class BookData {
  int _id;
  String title;
  String author;
  String publisher;
  int price;
}

dfdfas

/*
도서관리 앱에서 ListView로 화면에 표시하기 위해 ArrayList<BookData>에 책들의
정보를 넣어 인텐트로 넘겨주려고 하면 BookData 클래스를 그대로 사용할수는 없다.
co
오브젝트를 Parcelable 클래스로 만들어 주려면 android.os.Parcelable 인터페이스를
구현해야 한다. 그러므로 아래와 같이 클래스 정의를 변경한다.
*/
public class BookData implements Parcelable {
  int _id;
  String title;
  String author;
  String publisher;
  int price;
}

/*
그리고 android.os.Parcelable 인터페이스에 있는 2개의 메소드를 오버라이드 해 줘야만 한다.
describeContents() - Parcel 하려는 오브젝트의 종류를 정의한다.
writeToParcel(Parcel dest, int flags)
- 실제 오브젝트 serialization/flattening을 하는 메소드. 오브젝트의 각 엘리먼트를
각각 parcel해줘야 한다
*/
public void writeToParcel(Parcel dest, int flags) {
  dest.writeInt(_id);
  dest.writeString(title);
  dest.writeString(author);
  dest.writeString(publisher);
  dest.writeInt(price);
}

/*
다음으로 해야 할 일은 Parcel에서 데이터를 un-marshal/de-serialize하는
단계를 추가해줘야 한다. 그러기 위해서 Parcelable.Creator 타입의 CREATOR라는 변수를
정의해야 한다.
이 변수를 정의하지 않으면 안드로이드는 다음과 같은 익셉션을 발생한다.

Parcelable protocol requires a Parcelable.Creator object called CREATOR
*/

//아래는 위의 예제인 BookData 클래스를 위한 Parcelable.Creator<BookData>의 코드이다.
public class CustomCreator implements Parcelable.Creator<BookData> {
  public BookData createFromParcel(Parcel src) {
    return new BookData(src);
  }

  public BookData[] newArray(int size) {
    return new BookData[size];
  }
}

//BookData.java에 모든 parcel된 데이터를 복구하는 생성자를 정의해 줘야만 한다.
public BookData(Parcel src) {
   _id = src.readInt();
   title = src.readString();
   author = src.readString();
   publisher = src.readString();
   price = src.readInt();
 }

 //주의할것은 writeToParcel() 메소드에서 기록한 순서와 동일하게 복구해야만 한다.
//전체 코드는 다음과 같다.
public class BookData implements Parcelable {
    private String title;
    private String author;
    private String publisher;
    private String isbn;
    private String description;
    private int price;
    private String photoUrl;

    public BookData() {
    }

    public BookData(Parcel in) {
       readFromParcel(in);
    }

    public BookData(String _title, String _author, String _pub, String _isbn, String _desc, int _price, String _photoUrl) {
         this.title = _title;
         this.author = _author;
         this.publisher = _pub;
         this.isbn = _isbn;
         this.description = _desc;
         this.price = _price;
         this.photoUrl = _photoUrl;
    }

// -------------------------------------------------------------------------
// Getters & Setters section - 각 필드에 대한 get/set 메소드들
// 여기서는 생략했음
// ....
// ....
// -------------------------------------------------------------------------


   public void writeToParcel(Parcel dest, int flags) {
           dest.writeString(title);
           dest.writeString(author);
           dest.writeString(publisher);
           dest.writeString(isbn);
           dest.writeString(description);
           dest.writeString(photoUrl);
           dest.writeInt(price);
   }

   private void readFromParcel(Parcel in){
           title = in.readString();
           author = in.readString();
           publisher = in.readString();
           isbn = in.readString();
           description = in.readString();
           photoUrl = in.readString();
           price = in.readInt();
   }

   public static final Parcelable.Creator CREATOR = new Parcelable.Creator() {
        public BookData createFromParcel(Parcel in) {
             return new BookData(in);
       }

       public BookData[] newArray(int size) {
            return new BookData[size];
       }
   };
}

//Parcelable 오브젝트를 인텐트로 보내는 경우는 다음과 같이 하면 된다.
BookData book = new BookData();
// 각 필드에 값을 넣어줌

Intent i = new Intent(this, ShowBook.class);
i.putExtra("bookInfo", book);
startActivity(i);

//인텐트를 받을 ShowBook.java에서는 다음과 같이 Parcelable 오브젝트를 복구하면 된다.
Bundle bundle = getIntent().getExtras();
BookData book = bundle.getParcelable("bookInfo");

//ArrayList<BookData>인 경우는 Intent를 만들어 보내는 쪽에서는 다음과 같이 하면 된다.
ArrayList<BookData> bookList = new ArrayList<BookData>();
...
// bookList.add() 메소드를 사용해서 bookList에 BookData 엔트리를 추가
...

Intent i = new Intent(this, BookList.class);
i.putParcelableArrayListExtra("myBooks", bookList);
startActivity(i);

//BookList.java (인텐트에 의해 호출되는 액티비티)에서는 다음과 같이 오브젝트를 복구하면 된다.
ArrayList<BookData> bookList;
...
Intent i = getIntent();
bookList = i.getParcelableArrayListExtra("myBooks");
