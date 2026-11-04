
int FUN_005f8000(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  longlong lVar3;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined1 auStack_10 [16];
  
  puVar1 = param_1;
  param_1 = (void *)0x0;
  local_18 = puVar1[2];
  local_14 = puVar1[3];
  local_1c = 0;
  if (((code *)puVar1[0xb1] == (code *)0x0) || (puVar1[0xb3] == 0)) {
    puVar1[4] = 0xffffffff;
    puVar1[2] = 0xffffffff;
    puVar1[5] = 0xffffffff;
    puVar1[3] = 0xffffffff;
  }
  else {
    (*(code *)puVar1[0xb1])(*puVar1,0,0,2);
    iVar2 = (*(code *)puVar1[0xb3])(*puVar1);
    puVar1[4] = iVar2;
    puVar1[5] = iVar2 >> 0x1f;
    puVar1[2] = puVar1[4];
    puVar1[3] = iVar2 >> 0x1f;
  }
  if ((puVar1[4] & puVar1[5]) == 0xffffffff) {
    return -0x83;
  }
  lVar3 = FUN_005f8150(puVar1,puVar1[2],puVar1[3],auStack_10);
  if ((lVar3 < 0x100000000) && (lVar3 < 0)) {
    return (int)lVar3;
  }
  iVar2 = FUN_006a9a90(puVar1,0,0);
  if ((iVar2 == 0) && (iVar2 = FUN_005f82a0(puVar1,&param_1,&local_1c), iVar2 == 0)) {
    iVar2 = FUN_005f8410(puVar1,0,0,0,0,lVar3 + 1,param_1,local_1c,0);
    if (iVar2 < 0) {
      return -0x80;
    }
    if (param_1 != (void *)0x0) {
      _free(param_1);
    }
    FUN_005f8650(puVar1,local_18,local_14);
    iVar2 = FUN_005f8b30(puVar1,0,0);
  }
  return iVar2;
}

