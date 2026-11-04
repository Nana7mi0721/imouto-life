
int __fastcall FUN_00600b50(int *param_1)

{
  int iVar1;
  int unaff_EBX;
  int unaff_ESI;
  undefined1 local_8 [8];
  
  if (param_1[0x12] == 1) {
    return -0x7fffbffb;
  }
  iVar1 = (**(code **)(*param_1 + 0x2c))(param_1,local_8);
  if (iVar1 < 0) {
    return iVar1;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 7));
  param_1[0x10] = unaff_ESI;
  param_1[0xe] = unaff_ESI;
  param_1[0x11] = unaff_EBX;
  param_1[0xf] = unaff_EBX;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 7));
  return iVar1;
}

