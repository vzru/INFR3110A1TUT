using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Runtime.InteropServices;
using System;

public class FileManager_Plugin : MonoBehaviour
{
    const string DLL_NAME = "SaveLoadPlugin";

    //[DllImport(DLL_NAME)]
    //static extern void SetUpLoadPos(Action<float, float, float> action);

    [DllImport(DLL_NAME)]
    static extern void Save(float x, float y, float z, IntPtr ptr);

    [DllImport(DLL_NAME)]
    static extern void Load(IntPtr ptr); // this prep the data

    //[DllImport(DLL_NAME)]
    //static extern int LoadInt(); // Debugger

    [DllImport(DLL_NAME)]
    private static extern float GetXPos(IntPtr ptr);

    [DllImport(DLL_NAME)]
    private static extern float GetYPos(IntPtr ptr);

    [DllImport(DLL_NAME)]
    private static extern float GetZPos(IntPtr ptr);

    [DllImport(DLL_NAME)]
    static extern IntPtr CreateManager();

    IntPtr SaveManager;

    //public void Call(float x, float y, float z)
    //{
    //    transform.position = new Vector3(x, y, z);
    //}
    // Start is called before the first frame update
    void Start()
    {
        SaveManager = CreateManager();
        //SetUpLoadPos(Call);
    }

    // Update is called once per frame
    void Update()
    {
        //Debug.Log(transform.position);
        if (Input.GetKeyDown(KeyCode.I))
        {
            Save(this.transform.position.x, this.transform.position.y, this.transform.position.z, SaveManager);
            Debug.Log(this.transform.position);
        }
        if (Input.GetKeyDown(KeyCode.O))
        {
            Load(SaveManager);
            //Debug.Log(LoadInt());
            float _x = GetXPos(SaveManager);
            float _y = GetYPos(SaveManager);
            float _z = GetZPos(SaveManager);

            Debug.Log(_x);
            Debug.Log(this.transform.position);
            Debug.Log(_y);
            Debug.Log(_z);
            // 1,2,3 is the initial values so they never got changes from the read file

            this.transform.position = new Vector3(_x, _y, _z); // ya it's weird
        }
    }
}
