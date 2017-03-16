/**
Check System Version at Runtime
Android provides a unique code for each platform version
in the Build constants class. Use these codes within your app
to build conditions that ensure the code that depends on higher API levels is
 executed only when those APIs are available on the system.
*/
private void setUpActionBar() {
    // Make sure we're running on Honeycomb or higher to use ActionBar APIs
    if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.HONEYCOMB) {
        ActionBar actionBar = getActionBar();
        actionBar.setDisplayHomeAsUpEnabled(true);
    }
}
/**

Note: When parsing XML resources, Android ignores XML attributes
that aren’t supported by the current device. So you can safely use XML attributes
that are only supported by newer versions without worrying
about older versions breaking when they encounter that code. For example,
if you set the targetSdkVersion="11", your app includes the ActionBar 
by default on Android 3.0 and higher. To then add menu items to the action bar,
 you need to set android:showAsAction="ifRoom" in your menu resource XML.
 It's safe to do this in a cross-version XML file, because
 the older versions of Android simply ignore the showAsAction attribute
 (that is, you do not need a separate version in res/menu-v11/)
*/
