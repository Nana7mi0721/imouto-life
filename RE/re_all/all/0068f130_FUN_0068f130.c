
int FUN_0068f130(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int *piStack_c;
  
  iVar2 = param_1[0x19];
  iVar3 = param_1[0x15];
  iVar8 = 1;
  do {
    iVar7 = iVar8;
    iVar8 = iVar7 + 1;
    iVar5 = iVar8;
    if (1 < iVar2) {
      iVar6 = iVar2 + -1;
      do {
        iVar5 = iVar5 * iVar8;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
  } while (iVar5 <= iVar3);
  if (iVar7 < 2) {
    *(undefined4 *)(*param_1 + 0x14) = 0x3a;
    *(int *)(*param_1 + 0x18) = iVar5;
    (**(code **)*param_1)(param_1);
  }
  iVar8 = 1;
  if (0 < iVar2) {
    piVar9 = param_2;
    for (iVar5 = iVar2; iVar6 = iVar2, iVar5 != 0; iVar5 = iVar5 + -1) {
      *piVar9 = iVar7;
      piVar9 = piVar9 + 1;
    }
    do {
      iVar8 = iVar8 * iVar7;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  do {
    iVar5 = 0;
    bVar4 = false;
    if (iVar2 < 1) {
      return iVar8;
    }
    piStack_c = &DAT_00823630;
    iVar7 = iVar8;
    do {
      if (param_1[0xb] == 2) {
        iVar6 = *piStack_c;
      }
      else {
        iVar6 = iVar5;
      }
      iVar1 = param_2[iVar6] + 1;
      iVar8 = (iVar7 / param_2[iVar6]) * iVar1;
      if (iVar3 < iVar8) {
        iVar8 = iVar7;
        if (!bVar4) {
          return iVar7;
        }
        break;
      }
      iVar5 = iVar5 + 1;
      param_2[iVar6] = iVar1;
      piStack_c = piStack_c + 1;
      bVar4 = true;
      iVar7 = iVar8;
    } while (iVar5 < iVar2);
  } while( true );
}

