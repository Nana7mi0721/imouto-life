
undefined4
FUN_005be8b0(int *param_1,undefined4 param_2,undefined4 param_3,uint param_4,char *param_5,
            undefined4 param_6,undefined4 param_7,undefined4 param_8,int param_9,int param_10)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int local_34;
  int *local_30;
  undefined4 local_2c;
  undefined1 local_20 [16];
  undefined1 local_10 [16];
  
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  FUN_00568ca0(param_10);
  if (DAT_00dda46c != 0) {
    FUN_00584d70();
  }
  cVar1 = *param_5;
  if ((((cVar1 == '\x01') || (cVar1 == '\x02')) || (cVar1 == '\x03')) ||
     ((cVar1 == '\x04' || (local_2c = 0, cVar1 == '\x05')))) {
    local_2c = 1;
  }
  iVar6 = param_1[2] - *param_1;
  iVar7 = param_1[3] - param_1[1];
  if ((iVar6 < 1) || (iVar7 < 1)) {
    return 0;
  }
  if (param_10 == 0) {
    if ((((DAT_00cc47d0 != 0) && (-1 < (int)param_4)) && ((param_4 & 0x7c000000) == DAT_00cc47f8))
       && ((((int)(param_4 & 0xffff) < DAT_00cc4800 &&
            (local_30 = *(int **)(DAT_00cc47d4 + (param_4 & 0xffff) * 4), local_30 != (int *)0x0))
           && ((*local_30 * 0x10000 == (param_4 & 0x3ff0000) && (local_30[4] == 0))))))
    goto LAB_005be9e5;
  }
  else if (((DAT_00cc47d0 != 0) && (-1 < (int)param_4)) &&
          (((param_4 & 0x7c000000) == DAT_00cc47f8 &&
           ((((int)(param_4 & 0xffff) < DAT_00cc4800 &&
             (local_30 = *(int **)(DAT_00cc47d4 + (param_4 & 0xffff) * 4), local_30 != (int *)0x0))
            && (*local_30 * 0x10000 == (param_4 & 0x3ff0000))))))) {
LAB_005be9e5:
    iVar2 = local_30[0x13];
    uVar4 = FUN_005b85a0(*(undefined4 *)(&DAT_00ee9a58 + *(int *)(iVar2 + 4) * 4));
    local_34 = 0;
    if (param_9 == 1) {
      piVar8 = (int *)(iVar2 + 0x3c);
      if (0 < *(int *)(iVar2 + 0x38)) {
        do {
          iVar5 = FUN_00518d50(piVar8,param_1,iVar6,iVar7,param_2,param_3,local_20,local_10,local_2c
                              );
          if (-1 < iVar5) {
            if (*(int *)(iVar2 + 0x34) < 2) {
              iVar5 = FUN_005be4a0(iVar2,local_10,local_20,*(undefined4 *)(*piVar8 + 4),piVar8[5],
                                   piVar8[6],piVar8[3],piVar8[4],param_6,uVar4,param_7,param_8,
                                   param_10);
            }
            else {
              iVar5 = FUN_005bdf10(iVar2,local_10,local_20,*(undefined4 *)(*piVar8 + 4),piVar8[5],
                                   piVar8[6],param_5,param_6,uVar4,param_7,param_8,param_10);
            }
            if (iVar5 < 0) {
              return 0xffffffff;
            }
          }
          local_34 = local_34 + 1;
          piVar8 = piVar8 + 7;
        } while (local_34 < *(int *)(iVar2 + 0x38));
      }
    }
    else {
      piVar8 = local_30 + 0x23;
      if (0 < local_30[0x22]) {
        do {
          iVar5 = FUN_00518f40(piVar8,param_1,iVar6,iVar7,param_2,param_3,local_20,local_10,local_2c
                              );
          if (-1 < iVar5) {
            piVar3 = (int *)piVar8[0x1d];
            if (*(int *)(iVar2 + 0x34) < 2) {
              iVar5 = FUN_005be4a0(iVar2,local_10,local_20,*(undefined4 *)(*piVar3 + 4),piVar3[5],
                                   piVar3[6],piVar3[3],piVar3[4],param_6,uVar4,param_7,param_8,
                                   param_10);
            }
            else {
              iVar5 = FUN_005bdf10(iVar2,local_10,local_20,*(undefined4 *)(*piVar3 + 4),piVar3[5],
                                   piVar3[6],param_5);
            }
            if (iVar5 < 0) {
              return 0xffffffff;
            }
          }
          local_34 = local_34 + 1;
          piVar8 = piVar8 + 0x1e;
          if (local_30[0x22] <= local_34) {
            return 0;
          }
        } while( true );
      }
    }
    return 0;
  }
  return 0xffffffff;
}

