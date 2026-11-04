
undefined4 FUN_0056e7c0(int *param_1,int param_2)

{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  
  piVar2 = param_1;
  if (param_1[0x219] == 0) {
    return 0xffffffff;
  }
  if (*param_1 == 0) {
    piVar5 = param_1 + 0x12;
    param_1 = (int *)0x0;
    if ((*(int *)(param_2 + 0x14) != 0) || (*(int *)(param_2 + 0x10) != 0)) {
      piVar5 = (int *)(*piVar5 + *(int *)(param_2 + 0x18) + 0x28);
      do {
        if ((piVar5[-8] & 0x10U) == 0) {
          uVar1 = piVar5[2];
          if (uVar1 != 0 || piVar5[3] != 0) {
            uVar4 = piVar5[5];
            if ((piVar5[4] & uVar4) == 0xffffffff) {
              uVar4 = piVar5[3];
              uVar3 = uVar1;
              uVar6 = uVar4;
            }
            else {
              uVar3 = piVar5[4];
              uVar6 = piVar5[3];
            }
            FUN_0056e590(uVar3,uVar4,uVar1,uVar6,piVar2 + 0x216);
          }
        }
        else {
          FUN_0056e7c0(piVar2,piVar2[0x13] + *piVar5);
        }
        param_1 = (int *)((int)param_1 + 1);
        piVar5 = piVar5 + 0x10;
      } while ((*(int *)(param_2 + 0x14) != 0) || (param_1 < *(uint *)(param_2 + 0x10)));
    }
  }
  return 0;
}

