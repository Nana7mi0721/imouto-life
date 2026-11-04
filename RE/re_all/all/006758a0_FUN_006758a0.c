
int FUN_006758a0(int param_1,int param_2,int param_3,undefined4 param_4,int *param_5,int param_6,
                int *param_7)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined1 local_400 [1024];
  
  if (*(int *)(param_1 + 0x80) != param_2) {
    *(char **)(param_1 + 0x9c) = s_zstream_unclaimed_00a0cf00;
    return -2;
  }
  iVar4 = *param_5;
  iVar6 = *param_7;
  *(undefined4 *)(param_1 + 0x84) = param_4;
  *(undefined4 *)(param_1 + 0x88) = 0;
  *(undefined4 *)(param_1 + 0x94) = 0;
  if (param_6 != 0) {
    *(int *)(param_1 + 0x90) = param_6;
  }
  do {
    iVar4 = iVar4 + *(int *)(param_1 + 0x88);
    iVar3 = -1;
    if (iVar4 != -1) {
      iVar3 = iVar4;
    }
    iVar4 = iVar4 - iVar3;
    *(int *)(param_1 + 0x88) = iVar3;
    uVar5 = iVar6 + *(int *)(param_1 + 0x94);
    uVar2 = 0xffffffff;
    if (param_6 == 0) {
      uVar2 = 0x400;
      *(undefined1 **)(param_1 + 0x90) = local_400;
    }
    if (uVar5 < uVar2) {
      uVar2 = uVar5;
    }
    iVar6 = uVar5 - uVar2;
    *(uint *)(param_1 + 0x94) = uVar2;
    if (iVar6 == 0) {
      cVar1 = (-(param_3 != 0) & 2U) + 2;
    }
    else {
      cVar1 = '\0';
    }
    iVar3 = FUN_0067abc0(param_1 + 0x84,cVar1);
  } while (iVar3 == 0);
  if (param_6 == 0) {
    *(undefined4 *)(param_1 + 0x90) = 0;
  }
  iVar4 = iVar4 + *(int *)(param_1 + 0x88);
  iVar6 = iVar6 + *(int *)(param_1 + 0x94);
  if (iVar6 != 0) {
    *param_7 = *param_7 - iVar6;
  }
  if (iVar4 != 0) {
    *param_5 = *param_5 - iVar4;
  }
  FUN_00669790(param_1,iVar3);
  return iVar3;
}

