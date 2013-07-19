package com.yzTest;

import vehicle_DSP.YZ_VehicleTransit_CVS;
import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;

public class MainActivity extends Activity {
	private Button button1;
	private EditText text1;
	private EditText text2;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        button1 = (Button)findViewById(R.id.button1);
        text1 = (EditText)findViewById(R.id.editText1);
        text2 = (EditText)findViewById(R.id.editText2);
        button1.setOnClickListener(new OnClickListener(){

			@Override
			public void onClick(View v) {
				String lowercase = text1.getText().toString();
				String uppercase = YZ_VehicleTransit_CVS.capitalize(lowercase);
				text2.setText(uppercase);
				
			}
        	
        	
        });
    }


    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.main, menu);
        return true;
    }
    
}
