package com.example.android_vigenere;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends Activity implements OnClickListener {

	Button btnCifrar;
	EditText etTexto, etClave;
	TextView tvSalida;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);

		btnCifrar = (Button) findViewById(R.id.btnCifrar);
		etTexto = (EditText) findViewById(R.id.etTexto);
		etClave = (EditText) findViewById(R.id.etClave);
		tvSalida = (TextView) findViewById(R.id.tvSalida);

		tvSalida.setVisibility(View.GONE);
		btnCifrar.setOnClickListener(this);

	}

	@Override
	public void onClick(View v) {
		switch (v.getId()) {
		case R.id.btnCifrar:
			String sTexto = etTexto.getText().toString().toUpperCase();
			String sClave = etClave.getText().toString().toUpperCase();
			String salida;
			Vigenere vigenere = new Vigenere();
			
			salida = vigenere.cifrar(sTexto, sClave);
			
			tvSalida.setText("Texto cifrado: "+salida.toLowerCase());
			tvSalida.setVisibility(View.VISIBLE);

			break;
		}
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}

}
