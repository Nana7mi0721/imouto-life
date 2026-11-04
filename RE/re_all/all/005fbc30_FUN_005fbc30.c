
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005fbc30(int param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  int *piVar1;
  int *piVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  byte *pbVar18;
  undefined1 *puVar19;
  int *piVar20;
  int local_4f0;
  int local_4ec;
  byte *local_4e8;
  int local_4e0;
  int local_4dc;
  undefined4 local_4c0;
  undefined4 local_4bc;
  int local_4b8;
  int local_4b4;
  undefined1 local_4ac [12];
  undefined4 local_4a0;
  undefined4 local_49c;
  undefined1 local_440;
  undefined1 local_43f;
  undefined1 local_43e;
  undefined1 local_43c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  if ((((param_4 == 0) || (*(int *)(param_1 + 0x940) != 0)) || (*(int *)(param_1 + 0x934) == 0)) &&
     (((param_3 == 0 || (*(int *)(param_1 + 0x950) != 0)) || (*(int *)(param_1 + 0x944) == 1)))) {
    if (param_2 == 0) {
      return 0;
    }
    if (*(int *)(param_1 + 0x92c) != 0) {
      return 0;
    }
  }
  while( true ) {
    FUN_0056da60(param_1,s_D__DxLib_Develop_Source_Library__00a05f80,0x11dc);
    iVar14 = *(int *)(param_1 + 0x220);
    while (((iVar14 != 0 && (*(int *)(param_1 + 0x220) != 1)) && (*(int *)(param_1 + 0x220) != 4)))
    {
      if (*(int *)(param_1 + 0x220) == 3) goto LAB_005fbd87;
      FUN_0056dac0(param_1);
      FUN_0056da20(1);
      FUN_0056da60(param_1,s_D__DxLib_Develop_Source_Library__00a05f80,0x11dc);
      iVar14 = *(int *)(param_1 + 0x220);
    }
    if (*(int *)(param_1 + 0x220) == 3) break;
    piVar20 = *(int **)(param_1 + 0x4e4);
    iVar14 = 0;
    if (0 < *(int *)(param_1 + 0x4e8)) {
      do {
        if ((*piVar20 != 0) && (piVar20[1] == *(int *)(param_1 + 0x4d8))) break;
        iVar14 = iVar14 + 1;
        piVar20 = piVar20 + 10;
      } while (iVar14 < *(int *)(param_1 + 0x4e8));
    }
    if (iVar14 != *(int *)(param_1 + 0x4e8)) {
      FUN_0056dac0(param_1);
      if (((param_4 != 0) && (*(int *)(param_1 + 0x940) == 0)) && (*(int *)(param_1 + 0x934) != 0))
      {
        FUN_0060ae90(param_1,piVar20,param_5);
      }
      if (((param_3 != 0) && (*(int *)(param_1 + 0x944) == 0)) &&
         (iVar14 = thunk_FUN_00568c60(), 199 < iVar14)) {
        piVar1 = (int *)(param_1 + 0x948);
        if (*piVar1 == -1) {
          FUN_005193b0(local_4ac);
          FUN_005194a0(local_4ac,0x20,0,0);
          local_4a0 = 1;
          local_49c = 8;
          iVar14 = FUN_005243b0(local_4ac,piVar20[4],piVar20[5],0,0,0,0,param_5);
          *piVar1 = iVar14;
          FUN_00580830(*piVar1,piVar1);
        }
        piVar2 = (int *)(param_1 + 0x94c);
        if (*piVar2 == -1) {
          FUN_005193b0(local_4ac);
          FUN_005194a0(local_4ac,0x20,0,0);
          local_4a0 = 2;
          local_49c = 8;
          iVar14 = FUN_005243b0(local_4ac,piVar20[7],piVar20[8],0,0,0,0,param_5);
          *piVar2 = iVar14;
          FUN_00580830(*piVar2,piVar2);
        }
        FUN_0056d380(&local_440,0,0x440);
        local_4b8 = piVar20[4];
        local_4b4 = piVar20[5];
        local_10 = piVar20[6];
        local_c = piVar20[2];
        local_440 = 0;
        local_43c = 1;
        local_43f = 1;
        local_43e = 8;
        local_4c0 = 0;
        local_4bc = 0;
        local_18 = local_4b8;
        local_14 = local_4b4;
        FUN_00518620(&local_4c0,0,0,*piVar1,&local_440,0,0,0,0,param_5);
        local_4b8 = piVar20[7];
        local_4b4 = piVar20[8];
        local_10 = piVar20[9];
        local_c = piVar20[3];
        local_440 = 0;
        local_43c = 2;
        local_43f = 2;
        local_43e = 8;
        local_4c0 = 0;
        local_4bc = 0;
        local_18 = local_4b8;
        local_14 = local_4b4;
        FUN_00518620(&local_4c0,0,0,*piVar2,&local_440,0,0,0,0,param_5);
        *(undefined4 *)(param_1 + 0x950) = 1;
      }
      if ((param_2 != 0) && (*(int *)(param_1 + 0x92c) == 0)) {
        puVar19 = *(undefined1 **)(param_1 + 0x920);
        pbVar18 = (byte *)piVar20[2];
        local_4e8 = (byte *)piVar20[3];
        if ((piVar20[4] == piVar20[7] * 2) && (piVar20[5] == piVar20[8] * 2)) {
          iVar14 = piVar20[6];
          iVar4 = piVar20[4];
          iVar16 = piVar20[7];
          iVar17 = piVar20[9];
          iVar5 = *(int *)(param_1 + 0x91c);
          iVar6 = piVar20[4];
          iVar7 = piVar20[4];
          local_4dc = piVar20[5] / 2;
          if (0 < local_4dc) {
            do {
              if (0 < iVar7 / 2) {
                local_4e0 = iVar7 / 2;
                do {
                  iVar8 = (&DAT_00a50ef8)[local_4e8[1]];
                  iVar15 = (&DAT_00a512f8)[*local_4e8] + (&DAT_00a516f8)[local_4e8[1]];
                  iVar9 = (&DAT_00a51af8)[*local_4e8];
                  iVar10 = (&DAT_00a51ef8)[*pbVar18];
                  iVar11 = (&DAT_00a51ef8)[pbVar18[1]];
                  iVar12 = (&DAT_00a51ef8)[pbVar18[piVar20[6]]];
                  iVar13 = (&DAT_00a51ef8)[pbVar18[piVar20[6] + 1]];
                  puVar19[2] = (&DAT_00a524f8)[iVar10 + iVar8 >> 0xe];
                  puVar19[1] = (&DAT_00a524f8)[iVar10 + iVar15 >> 0xe];
                  uVar3 = (&DAT_00a524f8)[iVar10 + iVar9 >> 0xe];
                  puVar19[3] = 0xff;
                  *puVar19 = uVar3;
                  puVar19[6] = (&DAT_00a524f8)[iVar11 + iVar8 >> 0xe];
                  puVar19[5] = (&DAT_00a524f8)[iVar11 + iVar15 >> 0xe];
                  uVar3 = (&DAT_00a524f8)[iVar11 + iVar9 >> 0xe];
                  puVar19[7] = 0xff;
                  puVar19[4] = uVar3;
                  puVar19[iVar5 + 2] = (&DAT_00a524f8)[iVar12 + iVar8 >> 0xe];
                  puVar19[iVar5 + 1] = (&DAT_00a524f8)[iVar12 + iVar15 >> 0xe];
                  puVar19[iVar5] = (&DAT_00a524f8)[iVar12 + iVar9 >> 0xe];
                  puVar19[iVar5 + 3] = 0xff;
                  puVar19 = puVar19 + 8;
                  pbVar18 = pbVar18 + 2;
                  puVar19[iVar5 + -2] = (&DAT_00a524f8)[iVar8 + iVar13 >> 0xe];
                  local_4e8 = local_4e8 + 2;
                  puVar19[iVar5 + -3] = (&DAT_00a524f8)[iVar15 + iVar13 >> 0xe];
                  local_4e0 = local_4e0 + -1;
                  puVar19[iVar5 + -4] = (&DAT_00a524f8)[iVar13 + iVar9 >> 0xe];
                  puVar19[iVar5 + -1] = 0xff;
                } while (local_4e0 != 0);
              }
              puVar19 = puVar19 + (iVar5 + iVar6 * -2) * 2;
              pbVar18 = pbVar18 + (iVar14 * 2 - iVar4);
              local_4e8 = local_4e8 + iVar17 + iVar16 * -2;
              local_4dc = local_4dc + -1;
            } while (local_4dc != 0);
          }
        }
        else {
          iVar14 = piVar20[4];
          iVar4 = *(int *)(param_1 + 0x91c);
          local_4e0 = 0;
          if (0 < piVar20[5]) {
            do {
              local_4ec = 0;
              if (0 < piVar20[4]) {
                do {
                  local_4f0 = __ftol();
                  iVar16 = __ftol();
                  iVar17 = __ftol();
                  if (local_4f0 < 0) {
                    local_4f0 = 0;
                  }
                  else if (0xff < local_4f0) {
                    local_4f0 = 0xff;
                  }
                  if (iVar16 < 0) {
                    iVar16 = 0;
                  }
                  else if (0xff < iVar16) {
                    iVar16 = 0xff;
                  }
                  if (iVar17 < 0) {
                    iVar17 = 0;
                  }
                  else if (0xff < iVar17) {
                    iVar17 = 0xff;
                  }
                  *puVar19 = (char)iVar17;
                  puVar19[2] = (undefined1)local_4f0;
                  puVar19[1] = (char)iVar16;
                  puVar19[3] = 0xff;
                  local_4ec = local_4ec + 1;
                  puVar19 = puVar19 + 4;
                } while (local_4ec < piVar20[4]);
              }
              local_4e0 = local_4e0 + 1;
              puVar19 = puVar19 + iVar4 + iVar14 * -4;
            } while (local_4e0 < piVar20[5]);
          }
        }
        *(undefined4 *)(param_1 + 0x92c) = 1;
      }
      return 1;
    }
    if (*(int *)(param_1 + 0x238) == 1) break;
    FUN_0056dac0(param_1);
    FUN_0056da20(0);
  }
LAB_005fbd87:
  FUN_0056dac0(param_1);
  return 0;
}

