using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Runtime.InteropServices;
using System;

public class FileManager_Plugin : MonoBehaviour
{
    public Transform playerTransform;
    public Rigidbody playerBody;
    public float moveSpeed = 5.0f;

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
        playerTransform = this.GetComponent<Transform>();
        playerBody = this.GetComponent<Rigidbody>();
        //SetUpLoadPos(Call);
    }

    // Update is called once per frame
    void Update()
    {
        if(Input.GetKey(KeyCode.W))
        {
            playerBody.velocity = new Vector3(moveSpeed, 0, 0);
        }
        if (Input.GetKey(KeyCode.S))
        {
            playerBody.velocity = new Vector3(-moveSpeed, 0, 0);
        }
        if (Input.GetKey(KeyCode.A))
        {
            playerBody.velocity = new Vector3(0, 0, moveSpeed);
        }
        if (Input.GetKey(KeyCode.D))
        {
            playerBody.velocity = new Vector3(0, 0, -moveSpeed);
        }
        if (Input.GetKeyDown(KeyCode.I))
        {
            Save(playerTransform.position.x, playerTransform.position.y, playerTransform.position.z, SaveManager);
            Debug.Log(playerTransform.position);
        }
        if (Input.GetKeyDown(KeyCode.O))
        {
            Load(SaveManager);
            float _x = GetXPos(SaveManager);
            float _y = GetYPos(SaveManager);
            float _z = GetZPos(SaveManager);

            Debug.Log("X:" + _x);
            Debug.Log("Y:" + _y);
            Debug.Log("Z:" + _z);
            // 1,2,3 is the initial values so they never got changes from the read file

            playerTransform.position = new Vector3(_x, _y, _z);
        }
    }
}
