
int FUN_00595440(LPVOID param_1,int param_2,int param_3,DWORD param_4)

{
  DWORD DVar1;
  
  DVar1 = param_4;
  if (*(int *)(param_4 + 0x24) != 1) {
    ReadFile(*(HANDLE *)(param_4 + 0x20),param_1,param_2 * param_3,&param_4,(LPOVERLAPPED)0x0);
    return param_4;
  }
  WaitForSingleObject(*(HANDLE *)(param_4 + 0x40),0xffffffff);
  *(LPVOID *)(DVar1 + 0xc50) = param_1;
  *(undefined4 *)(DVar1 + 0x44) = 2;
  *(undefined4 *)(DVar1 + 0xc58) = *(undefined4 *)(DVar1 + 8);
  *(undefined4 *)(DVar1 + 0xc5c) = *(undefined4 *)(DVar1 + 0xc);
  *(int *)(DVar1 + 0xc60) = param_2 * param_3;
  ResetEvent(*(HANDLE *)(DVar1 + 0x40));
  SetEvent(*(HANDLE *)(DVar1 + 0x3c));
  if (*(int *)(DVar1 + 0x18) == 0) {
    WaitForSingleObject(*(HANDLE *)(DVar1 + 0x40),0xffffffff);
  }
  return param_2 * param_3;
}

