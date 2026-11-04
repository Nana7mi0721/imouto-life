
undefined4 FUN_0059e080(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  uint local_c;
  uint local_8;
  int local_4;
  
  iVar2 = FUN_005d4b00();
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  if (*(char *)(param_1 + 8) == '\0') {
    return 0;
  }
  if (*(int *)(&DAT_00ddb4d4 + *(int *)(param_1 + 4) * 4) == 0) {
    FUN_0056bb10(&DAT_007fc300);
    return 0xffffffff;
  }
  piVar6 = (int *)(param_1 + 0x3c);
  local_4 = 0;
  if (0 < *(int *)(param_1 + 0x38)) {
    do {
      iVar5 = 0;
      iVar2 = FUN_005d3600();
      if (iVar2 != 0) {
        *(undefined1 *)(param_1 + 0xd) = 0;
      }
      if (*(char *)(param_1 + 0xb) == '\0') {
LAB_0059e228:
        if (*(char *)(param_1 + 9) != '\0') goto LAB_0059e22e;
        if (*(int *)*piVar6 == 0) {
          if ((*(char *)(param_1 + 0xd) == '\0') || (*(char *)(param_1 + 0xb) != '\0')) {
            uVar4 = 0;
          }
          else {
            uVar4 = 1;
          }
          if (*(byte *)(param_1 + 0xf) == 0) {
            uVar3 = *(undefined4 *)(&DAT_00ddb4d4 + *(int *)(param_1 + 4) * 4);
          }
          else {
            uVar3 = *(undefined4 *)(&DAT_0085f9b8 + (uint)*(byte *)(param_1 + 0xf) * 4);
          }
          iVar2 = FUN_005d5820(piVar6[5],piVar6[6],*(undefined4 *)(param_1 + 0x34),
                               *(char *)(param_1 + 0xb) != '\0',uVar3,uVar4,(int *)*piVar6,0,param_2
                              );
          if (iVar2 != 0) {
            FUN_0056bb10(&DAT_007fc238);
            return 0xffffffff;
          }
        }
      }
      else {
        if (*(char *)(param_1 + 9) == '\0') {
          local_c = 0;
          local_8 = 0;
          if (*(byte *)(param_1 + 0x19) != 0) {
            local_8 = (uint)*(byte *)(param_1 + 0x1a);
            local_c = (uint)*(byte *)(param_1 + 0x19);
            FUN_005d5680(*(undefined4 *)(&DAT_00ddb4d4 + *(int *)(param_1 + 4) * 4),&local_c,
                         &local_8,0,param_2);
            if ((local_c != 0) && (*(int *)(*piVar6 + 0x1c) == 0)) {
              if (*(byte *)(param_1 + 0xf) == 0) {
                uVar4 = *(undefined4 *)(&DAT_00ddb4d4 + *(int *)(param_1 + 4) * 4);
              }
              else {
                uVar4 = *(undefined4 *)(&DAT_0085f9b8 + (uint)*(byte *)(param_1 + 0xf) * 4);
              }
              iVar2 = FUN_005d56e0(piVar6[5],piVar6[6],uVar4,local_c,local_8,0,
                                   (int *)(*piVar6 + 0x1c),0,param_2);
              if (iVar2 != 0) {
                FUN_0056bb10(&DAT_007fc25c);
                return 0xffffffff;
              }
            }
          }
          if (DAT_00a37d84 == 0) {
            if (local_c == 0) {
LAB_0059e1ab:
              if (*(int *)(param_1 + 0x28) == 0) {
                if (*(int *)(*piVar6 + 0x20) != 0) {
                  FUN_005d3370(*(int *)(*piVar6 + 0x20));
                  *(undefined4 *)(*piVar6 + 0x20) = 0;
                }
                goto LAB_0059e228;
              }
            }
          }
          else if (local_c != 0) goto LAB_0059e1ab;
          if (*(int *)(*piVar6 + 0x20) != 0) {
            FUN_005d3370(*(int *)(*piVar6 + 0x20));
            *(undefined4 *)(*piVar6 + 0x20) = 0;
          }
          iVar2 = FUN_005d5780(piVar6[5],piVar6[6],(&DAT_00ddb598)[*(int *)(param_1 + 0x2c)],local_c
                               ,local_8,0,*piVar6 + 0x20,0,param_2);
          if (iVar2 != 0) {
            FUN_0056bb10(&DAT_007fc2c0);
            return 0xffffffff;
          }
          goto LAB_0059e228;
        }
LAB_0059e22e:
        if (*(int *)*piVar6 == 0) {
          if ((*(char *)(param_1 + 0xd) == '\0') || (*(char *)(param_1 + 0xb) != '\0')) {
            uVar4 = 0;
          }
          else {
            uVar4 = 1;
          }
          if (*(byte *)(param_1 + 0xf) == 0) {
            uVar3 = *(undefined4 *)(&DAT_00ddb4d4 + *(int *)(param_1 + 4) * 4);
          }
          else {
            uVar3 = *(undefined4 *)(&DAT_0085f9b8 + (uint)*(byte *)(param_1 + 0xf) * 4);
          }
          iVar2 = FUN_005d58c0(piVar6[5],*(undefined4 *)(param_1 + 0x34),
                               *(char *)(param_1 + 0xb) != '\0',uVar3,uVar4,(int *)*piVar6,0,param_2
                              );
          if (iVar2 != 0) {
            FUN_0056bb10(&DAT_007fc28c);
            return 0xffffffff;
          }
        }
      }
      if (*(char *)(param_1 + 9) == '\0') {
        puVar1 = (undefined4 *)*piVar6;
        if ((puVar1[1] == 0) && (iVar2 = FUN_005d5cc0(*puVar1,0,puVar1 + 1,param_2), iVar2 != 0)) {
          FUN_0056bb10(&DAT_007fc1c0);
          return 0xffffffff;
        }
      }
      else {
        do {
          puVar1 = (undefined4 *)*piVar6;
          if ((puVar1[iVar5 + 1] == 0) &&
             (iVar2 = FUN_005d5dd0(*puVar1,iVar5,0,puVar1 + iVar5 + 1,param_2), iVar2 != 0)) {
            FUN_0056bb10(&DAT_007fc1f8);
            return 0xffffffff;
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < 6);
      }
      iVar2 = 0;
      if (*(char *)(param_1 + 0xb) != '\0') {
        do {
          if (*(int *)(*piVar6 + 4 + iVar2) != 0) {
            FUN_005d5950(*(undefined4 *)(*piVar6 + 4 + iVar2),0,0,param_2);
          }
          iVar2 = iVar2 + 4;
        } while (iVar2 < 0x18);
      }
      local_4 = local_4 + 1;
      piVar6 = piVar6 + 7;
    } while (local_4 < *(int *)(param_1 + 0x38));
  }
  return 0;
}

