/****************************************************************************
 * Copyright (c) 2023 BlazingStellar
 * 
 * This program and the accompanying materials are made available 
 * under the terms of the 
 * 		Eclipse Public License 2.0 
 * which is available at 
 * 		http://www.eclipse.org/legal/epl-2.0 
 * 
 * SPDX-License-Identifier: EPL-2.0
 ****************************************************************************
 */
package indi.blazing.stellar.jni.TDOMEncryptOrDecryptFileReborn;

import java.io.Closeable;
import java.util.Arrays;

public class StateDataWorker 
		implements Closeable {
	
	static {
		System.loadLibrary("build/libindi_blazing_stellar_jni_TDOMEncryptOrDecryptFileReborn");
	}
	
	private final long address;
	
	public StateDataWorker() {
		address = getNewObjectPointer();
	}
	
	private static native long getNewObjectPointer();
	
	public native byte[] encrypter(byte[] plainData, byte[] key);
	
	public native byte[] decrypter(byte[] cipherData, byte[] key);
	
	public native byte[] encrypterWithoutPadding(byte[] plainData, byte[] key);
	
	public native byte[] decrypterWithoutUnpadding(byte[] cipherData, byte[] key);
	
	@Override
	public native void close();
	
	public static void main(String[] args) {
		StateDataWorker obj = new StateDataWorker();
		byte[] plainData = new byte[10485760];
		byte[] key = new byte[5120];
		Arrays.fill(plainData, (byte)1);
		Arrays.fill(key, (byte)114);
		byte[] cipherData = obj.encrypter(plainData, key);
		obj.close();
		for(int v: cipherData) {
			System.out.println(v);
		}
	}
}
