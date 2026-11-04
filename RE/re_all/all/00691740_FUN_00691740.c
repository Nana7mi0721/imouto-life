
undefined1 FUN_00691740(int param_1,short *param_2,int *param_3,int param_4,undefined4 *param_5)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar4 = param_1;
  piVar1 = *(int **)(param_1 + 0x20);
  piVar2 = (int *)piVar1[0x5c];
  iVar3 = piVar1[0x5d];
  iVar7 = (int)*param_2 - (int)param_3;
  iVar6 = iVar7;
  if (iVar7 < 0) {
    iVar6 = -iVar7;
    iVar7 = iVar7 + -1;
  }
  iVar8 = 0;
  if (iVar6 != 0) {
    do {
      iVar8 = iVar8 + 1;
      iVar6 = iVar6 >> 1;
    } while (iVar6 != 0);
    if (0xb < iVar8) {
      *(undefined4 *)(*piVar1 + 0x14) = 6;
      (**(code **)**(undefined4 **)(param_1 + 0x20))(*(undefined4 **)(param_1 + 0x20));
    }
  }
  cVar5 = FUN_00691670(param_1,*(undefined4 *)(param_4 + iVar8 * 4),
                       (int)*(char *)(iVar8 + 0x400 + param_4));
  if (cVar5 == '\0') {
    return 0;
  }
  if ((iVar8 != 0) && (cVar5 = FUN_00691670(param_1,iVar7,iVar8), cVar5 == '\0')) {
    return 0;
  }
  iVar6 = 0;
  param_4 = 1;
  if (0 < iVar3) {
    param_3 = piVar2;
    do {
      param_3 = param_3 + 1;
      param_1 = (int)param_2[*param_3];
      if (param_1 == 0) {
        iVar6 = iVar6 + 1;
      }
      else {
        for (; 0xf < iVar6; iVar6 = iVar6 + -0x10) {
          cVar5 = FUN_00691670(iVar4,param_5[0xf0],(int)*(char *)(param_5 + 0x13c));
          if (cVar5 == '\0') {
            return 0;
          }
        }
        iVar7 = param_1;
        if (param_1 < 0) {
          iVar7 = -param_1;
          param_1 = param_1 + -1;
        }
        iVar7 = iVar7 >> 1;
        iVar8 = 1;
        if (iVar7 != 0) {
          do {
            iVar8 = iVar8 + 1;
            iVar7 = iVar7 >> 1;
          } while (iVar7 != 0);
          if (10 < iVar8) {
            *(undefined4 *)(**(int **)(iVar4 + 0x20) + 0x14) = 6;
            (**(code **)**(undefined4 **)(iVar4 + 0x20))(*(undefined4 **)(iVar4 + 0x20));
          }
        }
        iVar6 = iVar6 * 0x10 + iVar8;
        cVar5 = FUN_00691670(iVar4,param_5[iVar6],(int)*(char *)(iVar6 + 0x400 + (int)param_5));
        if (cVar5 == '\0') {
          return 0;
        }
        cVar5 = FUN_00691670(iVar4,param_1,iVar8);
        if (cVar5 == '\0') {
          return 0;
        }
        iVar6 = 0;
      }
      param_4 = param_4 + 1;
    } while (param_4 <= iVar3);
    if ((0 < iVar6) &&
       (cVar5 = FUN_00691670(iVar4,*param_5,(int)*(char *)(param_5 + 0x100)), cVar5 == '\0')) {
      return 0;
    }
  }
  return 1;
}

