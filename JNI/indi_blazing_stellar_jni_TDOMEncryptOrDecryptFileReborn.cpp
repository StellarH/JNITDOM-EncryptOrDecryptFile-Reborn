/****************************************************************************
 * Copyright (c) 2023 BlazingStellar
 * 
 * This program and the accompanying materials are made available 
 * under the terms of the 
 * 		GNU General Public License v3.0 only WITH Classpath exception 2.0
 * which is available at 
 * 		https://www.gnu.org/licenses/gpl-3.0-standalone.html 
 * and
 * 		https://www.gnu.org/software/classpath/license.html
 * 
 * SPDX-License-Identifier: GPL-3.0-only WITH Classpath-exception-2.0
 ****************************************************************************
 */
#include <bits/stdc++.h>
#include "indi_blazing_stellar_jni_TDOMEncryptOrDecryptFileReborn_StateDataWorker.h"
#include "IsFor_EODF_Reborn.hpp"

typedef Cryptograph::OaldresPuzzle_Cryptic::Version2::StateData_Worker<16, 32> StateData_Worker;
typedef Cryptograph::OaldresPuzzle_Cryptic::Version2::ImplementationDetails::CommonStateData<16, 32> CommonStateData;

StateData_Worker* getPointer(JNIEnv* env, jobject obj) {
	jclass cls = env-> GetObjectClass(obj);
	jfieldID field = env-> GetFieldID(cls, "address", "J");
	return (StateData_Worker*)(env-> GetLongField(obj, field));
}

/*
 * Class:     indi_blazing_stellar_jni_TDOMEncryptOrDecryptFileReborn_StateDataWorker
 * Method:    getNewObjectPointer
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_indi_blazing_stellar_jni_TDOMEncryptOrDecryptFileReborn_StateDataWorker_getNewObjectPointer
  (JNIEnv*, jclass) {
	std::vector<std::uint8_t> initialVector(2048, std::uint8_t{0x00});
	CommonStateData tmp((std::span<std::uint8_t>)initialVector, 12, 34);
	return (jlong)(new StateData_Worker(tmp));
}

/*
 * Class:     indi_blazing_stellar_jni_TDOMEncryptOrDecryptFileReborn_StateDataWorker
 * Method:    encrypter
 * Signature: ([C[C)[C
 */
JNIEXPORT jbyteArray JNICALL Java_indi_blazing_stellar_jni_TDOMEncryptOrDecryptFileReborn_StateDataWorker_encrypter
  (JNIEnv* env, jobject obj, jbyteArray plainData, jbyteArray key) {
	StateData_Worker* ptr = getPointer(env, obj);

	jbyte* PlainData = env-> GetByteArrayElements(plainData, nullptr);
	jsize PlainDataLen = env-> GetArrayLength(plainData);
	std::vector<unsigned char> vPlainData(PlainData, PlainData + PlainDataLen);

	jbyte* Key = env-> GetByteArrayElements(key, nullptr);
	jsize KeyLen = env-> GetArrayLength(key);
	std::vector<unsigned char> vKey(Key, Key + KeyLen);

	std::vector<unsigned char> v = ptr-> EncrypterMain(vPlainData, vKey);

	jbyteArray CipherData = env-> NewByteArray(v.size());
	env-> SetByteArrayRegion(CipherData, 0, v.size(), (jbyte*)v.data());

	return CipherData;
}
/*
 * Class:     indi_blazing_stellar_jni_TDOMEncryptOrDecryptFileReborn_StateDataWorker
 * Method:    decrypter
 * Signature: ([C[C)[C
 */
JNIEXPORT jbyteArray JNICALL Java_indi_blazing_stellar_jni_TDOMEncryptOrDecryptFileReborn_StateDataWorker_decrypter
  (JNIEnv* env, jobject obj, jbyteArray cipherData, jbyteArray key) {
	StateData_Worker* ptr = getPointer(env, obj);

	jbyte* CipherData = env-> GetByteArrayElements(cipherData, nullptr);
	jsize CipherDataLen = env-> GetArrayLength(cipherData);
	std::vector<unsigned char> vCipherData(CipherData, CipherData + CipherDataLen);

	jbyte* Key = env-> GetByteArrayElements(key, nullptr);
	jsize KeyLen = env-> GetArrayLength(key);
	std::vector<unsigned char> vKey(Key, Key + KeyLen);

	std::vector<unsigned char> v = ptr-> DecrypterMain(vCipherData, vKey);

	jbyteArray PlainData = env-> NewByteArray(v.size());
	env-> SetByteArrayRegion(PlainData, 0, v.size(), (jbyte*)v.data());

	return PlainData;
}

/*
 * Class:     indi_blazing_stellar_jni_TDOMEncryptOrDecryptFileReborn_StateDataWorker
 * Method:    encrypterWithoutPadding
 * Signature: ([C[C)[C
 */
JNIEXPORT jbyteArray JNICALL Java_indi_blazing_stellar_jni_TDOMEncryptOrDecryptFileReborn_StateDataWorker_encrypterWithoutPadding
  (JNIEnv* env, jobject obj, jbyteArray plainData, jbyteArray key) {
	StateData_Worker* ptr = getPointer(env, obj);

	jbyte* PlainData = env-> GetByteArrayElements(plainData, nullptr);
	jsize PlainDataLen = env-> GetArrayLength(plainData);
	std::vector<unsigned char> vPlainData(PlainData, PlainData + PlainDataLen);

	jbyte* Key = env-> GetByteArrayElements(key, nullptr);
	jsize KeyLen = env-> GetArrayLength(key);
	std::vector<unsigned char> vKey(Key, Key + KeyLen);

	std::vector<unsigned char> v = ptr-> EncrypterMainWithoutPadding(vPlainData, vKey);

	jbyteArray CipherData = env-> NewByteArray(v.size());
	env-> SetByteArrayRegion(CipherData, 0, v.size(), (jbyte*)v.data());

	return CipherData;
}

/*
 * Class:     indi_blazing_stellar_jni_TDOMEncryptOrDecryptFileReborn_StateDataWorker
 * Method:    decrypterWithoutPadding
 * Signature: ([C[C)[C
 */
JNIEXPORT jbyteArray JNICALL Java_indi_blazing_stellar_jni_TDOMEncryptOrDecryptFileReborn_StateDataWorker_decrypterWithoutUnpadding
  (JNIEnv* env, jobject obj, jbyteArray cipherData, jbyteArray key) {
	StateData_Worker* ptr = getPointer(env, obj);

	jbyte* CipherData = env-> GetByteArrayElements(cipherData, nullptr);
	jsize CipherDataLen = env-> GetArrayLength(cipherData);
	std::vector<unsigned char> vCipherData(CipherData, CipherData + CipherDataLen);

	jbyte* Key = env-> GetByteArrayElements(key, nullptr);
	jsize KeyLen = env-> GetArrayLength(key);
	std::vector<unsigned char> vKey(Key, Key + KeyLen);

	std::vector<unsigned char> v = ptr-> DecrypterMainWithoutUnpadding(vCipherData, vKey);

	jbyteArray PlainData = env-> NewByteArray(v.size());
	env-> SetByteArrayRegion(PlainData, 0, v.size(), (jbyte*)v.data());

	return PlainData;
}

/*
 * Class:     indi_blazing_stellar_jni_TDOMEncryptOrDecryptFileReborn_StateDataWorker
 * Method:    close
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_indi_blazing_stellar_jni_TDOMEncryptOrDecryptFileReborn_StateDataWorker_close
  (JNIEnv*env , jobject obj) {
	delete getPointer(env, obj);
}
