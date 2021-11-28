using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Prefab : MonoBehaviour
{
    public GameObject prefab;
    public int NumberOfObjects=35;
    public float Radius =20f;

    // Start is called before the first frame update
    void Start()
    {
        for (int j = 0; j < NumberOfObjects; j++)
        {
            for (int i = 0; i < NumberOfObjects; i++)
        {
            float angle= i * Mathf.PI * 2/ NumberOfObjects;
            Vector3 pos =new Vector3(Mathf.Cos(angle),j,Mathf.Sin(angle))*Radius;
            Instantiate(prefab,pos,Quaternion.identity);
        }
        }
    }

    
}
