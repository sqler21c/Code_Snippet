


ArrayAdapter<String> adapter = new ArrayAdapter<String>(this, R.layout.support_simple_spinner_dropdown_item, groups);
adapter.setDropDownViewResource(R.layout.support_simple_spinner_dropdown_item);
spinner.setAdapter(adapter);
