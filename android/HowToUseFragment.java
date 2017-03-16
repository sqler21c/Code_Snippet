import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.ViewGroup;


/**
To create a fragment, extend the Fragment class, then override
key lifecycle methods to insert your app logic,
 similar to the way you would with an Activity class.

One difference when creating a Fragment is
that you must use the onCreateView() callback to define the layout.
In fact, this is the only callback you need in order to get a fragment running.
For example, here's a simple fragment that specifies its own layout:
*/
public class ArticleFragment extends Fragment {
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
        Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        return inflater.inflate(R.layout.article_view, container, false);
    }
}
