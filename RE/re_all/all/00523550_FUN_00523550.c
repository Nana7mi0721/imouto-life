
int FUN_00523550(uint *param_1,undefined4 param_2,undefined1 *param_3,int param_4,undefined4 param_5
                ,int param_6)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  uint *puVar6;
  undefined4 local_70;
  uint local_6c [4];
  uint local_5c;
  uint local_3c;
  uint local_34;
  uint local_28;
  
  if (DAT_00a37d70 == 0) {
    return -1;
  }
  if (((param_6 == 0) && (DAT_00a21078 == 0)) && (DAT_00a238d0 == 0)) {
    FUN_0050e770();
  }
  if ((param_4 != 0) &&
     ((*(int *)(param_3 + 0x428) != *(int *)(param_4 + 0x428) ||
      (*(int *)(param_3 + 0x42c) != *(int *)(param_4 + 0x42c))))) {
    return -1;
  }
  cVar1 = '\0';
  param_1[7] = (uint)(*(int *)(param_3 + 0x43c) == 6);
  if ((((param_3[4] == '\x01') && ((DAT_00a37d78 != 0 || (param_3[0xb] == '\0')))) && (param_4 == 0)
      ) && (param_1[0x19] == 0)) {
    local_70 = 1;
    if ((DAT_00a37d9c == 0) || (param_3[5] != '\b')) {
      cVar1 = '\b';
    }
    else {
      iVar5 = *(int *)(param_3 + 0x24);
      if ((iVar5 == 0) || (iVar5 == 0xff)) {
        iVar5 = FUN_005424f0(param_3);
        cVar1 = (0xf < iVar5) * '\x04' + '\x04';
      }
      else {
        cVar1 = (0xf < iVar5) * '\x04' + '\x04';
      }
    }
  }
  else {
    local_70 = 0;
  }
  if (param_3[1] != '\0') {
    bVar2 = param_3[2];
    if (bVar2 != 0) {
      uVar3 = param_1[0xc];
      puVar6 = local_6c;
      for (iVar5 = 0x1b; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar6 = *param_1;
        param_1 = param_1 + 1;
        puVar6 = puVar6 + 1;
      }
      local_5c = (uint)bVar2;
      if (uVar3 == 0) {
        local_6c[2] = (uint)(byte)param_3[3];
        local_6c[3] = (uint)(byte)param_3[1];
      }
      else {
        local_34 = (uint)(byte)param_3[3];
        local_28 = (uint)(byte)param_3[1];
      }
      param_1 = local_6c;
      local_3c = uVar3;
    }
  }
  iVar5 = *(int *)(param_3 + 0x438);
  if (iVar5 == 0) {
    iVar5 = -1;
  }
  if ((param_3[0xb] == '\0') && (param_4 == 0)) {
    uVar4 = 0;
  }
  else {
    uVar4 = 1;
  }
  iVar5 = FUN_00522dc0(param_1,param_2,*(undefined4 *)(param_3 + 0x428),
                       *(undefined4 *)(param_3 + 0x42c),param_5,uVar4,local_70,cVar1,*param_3,iVar5,
                       param_6);
  return (iVar5 != -1) - 1;
}

