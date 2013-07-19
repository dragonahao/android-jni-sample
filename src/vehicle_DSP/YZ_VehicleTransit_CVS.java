package vehicle_DSP;

public class YZ_VehicleTransit_CVS {
	static{
		System.loadLibrary("YzTestJni");
	}
	
	public static native String capitalize(String words);
}
