
undefined4 __fastcall FUN_006073d0(int param_1)

{
  DWORD DVar1;
  HANDLE local_8;
  undefined4 local_4;
  
  local_8 = *(HANDLE *)(param_1 + 0x7c);
  local_4 = *(undefined4 *)(param_1 + 0x68);
  DVar1 = WaitForMultipleObjects(2,&local_8,0,0xffffffff);
  while (DVar1 == 1) {
    FUN_006072f0();
    DVar1 = WaitForMultipleObjects(2,&local_8,0,0xffffffff);
  }
  return 0;
}

