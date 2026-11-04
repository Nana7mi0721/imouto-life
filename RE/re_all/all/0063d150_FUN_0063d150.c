
undefined4 * __fastcall FUN_0063d150(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  FUN_00646840(6);
  FUN_005f5190(param_1 + 0x15,0x10,3,FUN_0061ddb0);
  FUN_005f5190(param_1 + 0x25,0x10,3,FUN_0061ddb0);
  local_c = 0;
  local_8 = 0;
  local_4 = 0;
  FUN_005fc530(&local_4,&local_8,&local_c);
  local_4 = 0;
  local_8 = 0;
  local_c = 0;
  FUN_005fc530(&local_c,&local_8,&local_4);
  local_4 = 0;
  local_8 = 0;
  local_c = 0;
  FUN_005fc530(&local_c,&local_8,&local_4);
  param_1[0xbf] = 0x3f333333;
  param_1[0xc0] = 0x3f800000;
  param_1[0xc1] = 0x3f000000;
  iVar1 = 0;
  puVar2 = param_1 + 199;
  do {
    *(undefined1 *)((int)param_1 + iVar1 + 0x308) = 0;
    puVar2[-4] = 0;
    *puVar2 = 0;
    iVar1 = iVar1 + 1;
    puVar2 = puVar2 + 1;
  } while (iVar1 < 3);
  iVar1 = 3;
  do {
    FUN_00640330();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  FUN_005f5190(param_1 + 0x101,0x10,3,FUN_0061ddb0);
  FUN_005f5190(param_1 + 0x111,0x10,3,FUN_0061ddb0);
  *(undefined1 *)(param_1 + 0x139) = 1;
  *(undefined1 *)((int)param_1 + 0x4e5) = 0;
  *param_1 = &PTR_LAB_008048d4;
  return param_1;
}

