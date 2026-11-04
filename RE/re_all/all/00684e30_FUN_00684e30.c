
uint FUN_00684e30(int *param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int *piStack_4;
  
  piVar2 = param_1;
  iVar3 = param_1[0x4c];
  if (iVar3 == 1) {
    iVar3 = param_1[0x4d];
    param_1[0x51] = *(int *)(iVar3 + 0x1c);
    param_1[0x52] = *(int *)(iVar3 + 0x20);
    uVar5 = *(uint *)(iVar3 + 0xc);
    *(undefined4 *)(iVar3 + 0x44) = *(undefined4 *)(iVar3 + 0x24);
    uVar1 = *(uint *)(iVar3 + 0x20);
    uVar4 = uVar1 % uVar5;
    *(undefined4 *)(iVar3 + 0x38) = 1;
    *(undefined4 *)(iVar3 + 0x3c) = 1;
    *(undefined4 *)(iVar3 + 0x40) = 1;
    *(undefined4 *)(iVar3 + 0x48) = 1;
    if (uVar4 == 0) {
      uVar4 = uVar5;
    }
    *(uint *)(iVar3 + 0x4c) = uVar4;
    param_1[0x53] = 1;
    param_1[0x54] = 0;
    return uVar1 / uVar5;
  }
  if ((iVar3 < 1) || (4 < iVar3)) {
    *(undefined4 *)(*param_1 + 0x14) = 0x1b;
    *(int *)(*param_1 + 0x18) = param_1[0x4c];
    *(undefined4 *)(*param_1 + 0x1c) = 4;
    (**(code **)*param_1)(param_1);
  }
  iVar3 = FUN_006848b0(param_1[7],param_1[0x46] * param_1[0x62]);
  param_1[0x51] = iVar3;
  iVar3 = FUN_006848b0(param_1[8],param_1[0x47] * param_1[0x62]);
  param_1[0x52] = iVar3;
  uVar5 = param_1[0x4c];
  param_1[0x53] = 0;
  param_1 = (int *)0x0;
  if (0 < (int)uVar5) {
    piStack_4 = piVar2 + 0x4d;
    do {
      iVar3 = *piStack_4;
      uVar5 = *(uint *)(iVar3 + 8);
      *(uint *)(iVar3 + 0x44) = *(int *)(iVar3 + 0x24) * uVar5;
      uVar4 = *(uint *)(iVar3 + 0x1c) % uVar5;
      uVar1 = *(uint *)(iVar3 + 0xc);
      *(uint *)(iVar3 + 0x38) = uVar5;
      *(uint *)(iVar3 + 0x3c) = uVar1;
      iVar6 = uVar1 * uVar5;
      *(int *)(iVar3 + 0x40) = iVar6;
      if (uVar4 == 0) {
        uVar4 = uVar5;
      }
      *(uint *)(iVar3 + 0x48) = uVar4;
      uVar5 = *(uint *)(iVar3 + 0x20) % uVar1;
      if (uVar5 == 0) {
        uVar5 = uVar1;
      }
      *(uint *)(iVar3 + 0x4c) = uVar5;
      if (10 < piVar2[0x53] + iVar6) {
        *(undefined4 *)(*piVar2 + 0x14) = 0xe;
        (**(code **)*piVar2)(piVar2);
      }
      if (0 < iVar6) {
        do {
          piVar2[piVar2[0x53] + 0x54] = (int)param_1;
          iVar6 = iVar6 + -1;
          piVar2[0x53] = piVar2[0x53] + 1;
        } while (iVar6 != 0);
      }
      uVar5 = (int)param_1 + 1;
      piStack_4 = piStack_4 + 1;
      param_1 = (int *)uVar5;
    } while ((int)uVar5 < piVar2[0x4c]);
  }
  return uVar5;
}

