
undefined1 FUN_00669c60(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_c;
  int local_8;
  int local_4;
  
  piVar3 = param_2;
  iVar4 = *param_2;
  if ((-1 < iVar4) && (iVar4 < 0x186a1)) {
    iVar6 = param_2[1];
    if ((((-1 < iVar6) &&
         ((((iVar6 <= 100000 - iVar4 && (iVar4 = param_2[2], -1 < iVar4)) && (iVar4 < 0x186a1)) &&
          ((-1 < param_2[3] && (param_2[3] <= 100000 - iVar4)))))) &&
        (iVar5 = param_2[4], -1 < iVar5)) &&
       ((((iVar5 < 0x186a1 && (iVar1 = param_2[5], -1 < iVar1)) &&
         ((iVar1 <= 100000 - iVar5 &&
          (((iVar2 = param_2[6], -1 < iVar2 && (iVar2 < 0x186a1)) && (-1 < param_2[7])))))) &&
        (param_2[7] <= 100000 - iVar2)))) {
      param_2 = (int *)iVar6;
      iVar4 = FUN_0066b150(&param_2,iVar4 - iVar5,iVar6 - iVar1,7);
      if (iVar4 == 0) {
        return 2;
      }
      iVar4 = FUN_0066b150(&local_c,piVar3[3] - piVar3[5],*piVar3 - piVar3[4],7);
      if (iVar4 == 0) {
        return 2;
      }
      iVar6 = (int)param_2 - local_c;
      iVar4 = FUN_0066b150(&param_2,piVar3[2] - piVar3[4],piVar3[7] - piVar3[5],7);
      if (iVar4 == 0) {
        return 2;
      }
      iVar4 = FUN_0066b150(&local_c,piVar3[3] - piVar3[5],piVar3[6] - piVar3[4],7);
      if (iVar4 == 0) {
        return 2;
      }
      iVar4 = FUN_0066b150(&local_8,piVar3[7],iVar6,(int)param_2 - local_c);
      if ((iVar4 != 0) && (piVar3[7] < local_8)) {
        iVar4 = FUN_0066b150(&param_2,piVar3[1] - piVar3[5],piVar3[6] - piVar3[4],7);
        if (iVar4 == 0) {
          return 2;
        }
        iVar4 = FUN_0066b150(&local_c,*piVar3 - piVar3[4],piVar3[7] - piVar3[5],7);
        if (iVar4 == 0) {
          return 2;
        }
        iVar4 = FUN_0066b150(&local_4,piVar3[7],iVar6,(int)param_2 - local_c);
        if ((iVar4 != 0) && (iVar4 = piVar3[7], iVar4 < local_4)) {
          iVar6 = FUN_0066b1d0(local_8);
          iVar4 = FUN_0066b1d0(iVar4);
          iVar5 = FUN_0066b1d0(local_4);
          iVar5 = (iVar4 - iVar6) - iVar5;
          if (0 < iVar5) {
            iVar4 = FUN_0066b150(param_1,*piVar3,100000,local_8);
            if (iVar4 != 0) {
              iVar4 = FUN_0066b150(param_1 + 4,piVar3[1],100000,local_8);
              if (iVar4 != 0) {
                iVar4 = FUN_0066b150(param_1 + 8,(100000 - *piVar3) - piVar3[1],100000,local_8);
                if (iVar4 != 0) {
                  iVar4 = FUN_0066b150(param_1 + 0xc,piVar3[2],100000,local_4);
                  if (iVar4 != 0) {
                    iVar4 = FUN_0066b150(param_1 + 0x10,piVar3[3],100000,local_4);
                    if (iVar4 != 0) {
                      iVar4 = FUN_0066b150(param_1 + 0x14,(100000 - piVar3[3]) - piVar3[2],100000,
                                           local_4);
                      if (iVar4 != 0) {
                        iVar4 = FUN_0066b150(param_1 + 0x18,piVar3[4],iVar5,100000);
                        if (iVar4 != 0) {
                          iVar4 = FUN_0066b150(param_1 + 0x1c,piVar3[5],iVar5,100000);
                          if (iVar4 != 0) {
                            iVar4 = FUN_0066b150(param_1 + 0x20,(100000 - piVar3[5]) - piVar3[4],
                                                 iVar5,100000);
                            return iVar4 == 0;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return true;
}

