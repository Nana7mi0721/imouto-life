
void FUN_00695240(int *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  if (((param_1[7] & 0xff000000U) != 0) || ((param_1[8] & 0xff000000U) != 0)) {
    *(undefined4 *)(*param_1 + 0x14) = 0x2a;
    *(undefined4 *)(*param_1 + 0x18) = 0xffdc;
    (**(code **)*param_1)(param_1);
  }
  iVar2 = param_1[0x5b];
  uVar4 = param_1[0xf] * iVar2;
  uVar1 = param_1[0xe];
  if (uVar4 <= uVar1) {
    param_1[0x10] = iVar2 * param_1[7];
    param_1[0x11] = param_1[8] * iVar2;
    param_1[0x42] = 1;
    param_1[0x43] = 1;
    return;
  }
  if (uVar4 <= uVar1 * 2) {
    iVar5 = 2;
    goto LAB_006953e0;
  }
  if (uVar4 <= uVar1 * 3) {
    iVar5 = 3;
LAB_0069536d:
    iVar2 = FUN_006848b0(iVar2 * param_1[7],iVar5);
    iVar3 = param_1[8] * param_1[0x5b];
    param_1[0x10] = iVar2;
    goto LAB_006953fa;
  }
  if (uVar4 <= uVar1 * 4) {
    iVar5 = 4;
    goto LAB_006953bf;
  }
  if (uVar4 <= uVar1 * 5) {
    iVar5 = 5;
    goto LAB_006953e0;
  }
  if (uVar4 <= uVar1 * 6) {
    iVar5 = 6;
    goto LAB_0069536d;
  }
  if (uVar4 <= uVar1 * 7) {
    iVar5 = 7;
    goto LAB_006953bf;
  }
  if (uVar4 <= uVar1 * 8) {
    iVar5 = 8;
    goto LAB_006953e0;
  }
  if (uVar4 <= uVar1 * 9) {
    iVar5 = 9;
    goto LAB_0069536d;
  }
  if (uVar4 <= uVar1 * 10) {
    iVar5 = 10;
    goto LAB_006953bf;
  }
  if (uVar4 <= uVar1 * 0xb) {
    iVar5 = 0xb;
    goto LAB_006953e0;
  }
  if (uVar4 <= uVar1 * 0xc) {
    iVar5 = 0xc;
    goto LAB_0069536d;
  }
  if (uVar1 * 0xd < uVar4) {
    if (uVar1 * 0xe < uVar4) {
      if (uVar4 <= uVar1 * 0xf) {
        iVar5 = 0xf;
        goto LAB_006953bf;
      }
      iVar5 = 0x10;
    }
    else {
      iVar5 = 0xe;
    }
LAB_006953e0:
    iVar2 = FUN_006848b0(iVar2 * param_1[7],iVar5);
    param_1[0x10] = iVar2;
    iVar3 = param_1[8] * param_1[0x5b];
  }
  else {
    iVar5 = 0xd;
LAB_006953bf:
    iVar2 = FUN_006848b0(iVar2 * param_1[7],iVar5);
    iVar3 = param_1[8] * param_1[0x5b];
    param_1[0x10] = iVar2;
  }
LAB_006953fa:
  iVar2 = FUN_006848b0(iVar3,iVar5);
  param_1[0x42] = iVar5;
  param_1[0x43] = iVar5;
  param_1[0x11] = iVar2;
  return;
}

