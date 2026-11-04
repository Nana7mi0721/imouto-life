
int FUN_00797f60(uint param_1,int param_2,uint *param_3,int *param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar7 = 0;
  iVar2 = FUN_00798960(2);
  iVar3 = FUN_00798960(1);
  uVar1 = param_1;
  iVar6 = param_1 + 0x10c;
  if (param_2 < 0xfc3) {
    if (param_2 == 0xfc2) {
      iVar7 = 0;
      if (*(int *)(param_1 + 4) < 1) {
        return 0;
      }
      while( true ) {
        if (iVar7 < *(int *)(uVar1 + 8)) {
          iVar5 = iVar2;
        }
        else {
          iVar5 = iVar3;
        }
        iVar4 = FUN_00799850(iVar6,0xfc2,param_3);
        if (iVar4 != 0) break;
        iVar7 = iVar7 + 1;
        iVar6 = iVar6 + (iVar5 + 3U & 0xfffffffc);
        if (*(int *)(uVar1 + 4) <= iVar7) {
          return 0;
        }
      }
      return iVar4;
    }
    switch(param_2) {
    case 0xfa9:
    case 0xfbd:
      goto switchD_00797fbb_caseD_fa9;
    default:
      return -5;
    case 0xfbc:
      iVar5 = 0;
      if (0 < *(int *)(param_1 + 4)) {
        while( true ) {
          if (iVar5 < *(int *)(uVar1 + 8)) {
            iVar4 = iVar2;
          }
          else {
            iVar4 = iVar3;
          }
          iVar7 = FUN_00799850(iVar6,0xfbc);
          if (iVar7 != 0) break;
          iVar5 = iVar5 + 1;
          iVar6 = iVar6 + (iVar4 + 3U & 0xfffffffc);
          if (*(int *)(uVar1 + 4) <= iVar5) {
            return 0;
          }
        }
      }
      break;
    case 0xfbf:
      if (param_3 == (uint *)0x0) {
        return -1;
      }
      *param_3 = 0;
      iVar5 = 0;
      if (0 < *(int *)(param_1 + 4)) {
        while( true ) {
          if (iVar5 < *(int *)(uVar1 + 8)) {
            iVar4 = iVar2;
          }
          else {
            iVar4 = iVar3;
          }
          iVar7 = FUN_00799850(iVar6,param_2,&param_1);
          if (iVar7 != 0) break;
          iVar5 = iVar5 + 1;
          *param_3 = *param_3 ^ param_1;
          iVar6 = iVar6 + (iVar4 + 3U & 0xfffffffc);
          if (*(int *)(uVar1 + 4) <= iVar5) {
            return 0;
          }
        }
      }
    }
  }
  else {
    if ((param_2 != 0xfc7) && (param_2 != 0xfcd)) {
      if (param_2 != 0x1402) {
        return -5;
      }
      if (((int)param_3 < 0) || (*(int *)(param_1 + 4) <= (int)param_3)) {
        iVar7 = -1;
      }
      if (param_4 == (int *)0x0) {
        return -1;
      }
      iVar5 = 0;
      if (0 < (int)param_3) {
        do {
          if (iVar5 < *(int *)(param_1 + 8)) {
            iVar4 = iVar2;
          }
          else {
            iVar4 = iVar3;
          }
          iVar5 = iVar5 + 1;
          iVar6 = iVar6 + (iVar4 + 3U & 0xfffffffc);
        } while (iVar5 < (int)param_3);
      }
      *param_4 = iVar6;
      return iVar7;
    }
switchD_00797fbb_caseD_fa9:
    iVar7 = FUN_00799850(iVar6,param_2,param_3);
  }
  return iVar7;
}

