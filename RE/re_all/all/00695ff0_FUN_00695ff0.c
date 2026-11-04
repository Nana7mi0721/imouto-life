
void FUN_00695ff0(int *param_1)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int *piStack_4;
  
  piVar3 = param_1;
  iVar4 = param_1[0x45];
  if (iVar4 == 1) {
    iVar4 = param_1[0x46];
    param_1[0x4a] = *(int *)(iVar4 + 0x1c);
    param_1[0x4b] = *(int *)(iVar4 + 0x20);
    *(undefined4 *)(iVar4 + 0x44) = *(undefined4 *)(iVar4 + 0x24);
    uVar5 = *(uint *)(iVar4 + 0x20) % *(uint *)(iVar4 + 0xc);
    *(undefined4 *)(iVar4 + 0x38) = 1;
    *(undefined4 *)(iVar4 + 0x3c) = 1;
    *(undefined4 *)(iVar4 + 0x40) = 1;
    *(undefined4 *)(iVar4 + 0x48) = 1;
    if (uVar5 == 0) {
      uVar5 = *(uint *)(iVar4 + 0xc);
    }
    *(uint *)(iVar4 + 0x4c) = uVar5;
    param_1[0x4c] = 1;
    param_1[0x4d] = 0;
  }
  else {
    if ((iVar4 < 1) || (4 < iVar4)) {
      *(undefined4 *)(*param_1 + 0x14) = 0x1b;
      *(int *)(*param_1 + 0x18) = param_1[0x45];
      *(undefined4 *)(*param_1 + 0x1c) = 4;
      (**(code **)*param_1)(param_1);
    }
    iVar4 = FUN_006848b0(param_1[0x10],param_1[0x40] * param_1[0x5b]);
    param_1[0x4a] = iVar4;
    iVar4 = FUN_006848b0(param_1[0x11],param_1[0x41] * param_1[0x5b]);
    param_1[0x4b] = iVar4;
    piVar1 = param_1 + 0x45;
    param_1[0x4c] = 0;
    param_1 = (int *)0x0;
    if (0 < *piVar1) {
      piStack_4 = piVar3 + 0x46;
      do {
        iVar4 = *piStack_4;
        uVar5 = *(uint *)(iVar4 + 8);
        *(uint *)(iVar4 + 0x44) = *(int *)(iVar4 + 0x24) * uVar5;
        uVar6 = *(uint *)(iVar4 + 0x1c) % uVar5;
        uVar2 = *(uint *)(iVar4 + 0xc);
        *(uint *)(iVar4 + 0x38) = uVar5;
        *(uint *)(iVar4 + 0x3c) = uVar2;
        iVar7 = uVar2 * uVar5;
        *(int *)(iVar4 + 0x40) = iVar7;
        if (uVar6 == 0) {
          uVar6 = uVar5;
        }
        *(uint *)(iVar4 + 0x48) = uVar6;
        uVar5 = *(uint *)(iVar4 + 0x20) % uVar2;
        if (uVar5 == 0) {
          uVar5 = uVar2;
        }
        *(uint *)(iVar4 + 0x4c) = uVar5;
        if (10 < piVar3[0x4c] + iVar7) {
          *(undefined4 *)(*piVar3 + 0x14) = 0xe;
          (**(code **)*piVar3)(piVar3);
        }
        if (0 < iVar7) {
          do {
            piVar3[piVar3[0x4c] + 0x4d] = (int)param_1;
            iVar7 = iVar7 + -1;
            piVar3[0x4c] = piVar3[0x4c] + 1;
          } while (iVar7 != 0);
        }
        param_1 = (int *)((int)param_1 + 1);
        piStack_4 = piStack_4 + 1;
      } while ((int)param_1 < piVar3[0x45]);
    }
  }
  if (0 < piVar3[0x39]) {
    iVar4 = piVar3[0x39] * piVar3[0x4a];
    if (0xfffe < iVar4) {
      iVar4 = 0xffff;
    }
    piVar3[0x38] = iVar4;
  }
  return;
}

