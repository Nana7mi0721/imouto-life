
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00460640(void)

{
  undefined4 *puVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_50;
  int local_4c;
  undefined1 local_48;
  undefined1 local_47 [11];
  undefined4 local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  uint local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_3c = DAT_0084b484;
  puVar1 = (undefined4 *)FUN_004ce990(1);
  local_18 = FUN_00487080(*puVar1);
  local_18 = local_18 + -1;
  puVar1 = (undefined4 *)FUN_004ce990(2);
  local_c = FUN_00487080(*puVar1);
  puVar1 = (undefined4 *)FUN_004ce990(3);
  local_1c = FUN_00487080(*puVar1);
  puVar1 = (undefined4 *)FUN_004ce990(4);
  local_10 = FUN_00487080(*puVar1);
  puVar1 = (undefined4 *)FUN_004ce990(5);
  local_8 = FUN_00487080(*puVar1);
  puVar1 = (undefined4 *)FUN_004ce990(6);
  local_14 = FUN_00487080(*puVar1);
  piVar2 = (int *)FUN_004ce990(6);
  if (*piVar2 < 1000000) {
    local_14 = FUN_00420d60(local_14);
  }
  if (((((-1 < local_18) && (local_18 < 3)) && (-1 < (int)local_14)) &&
      ((uVar3 = FUN_004ce080(), local_14 < uVar3 && (-1 < local_c)))) &&
     ((iVar4 = FUN_0047a490(), local_c < iVar4 &&
      ((-1 < local_1c && (iVar4 = FUN_0047a4b0(), local_1c < iVar4)))))) {
    iVar4 = FUN_0047a490();
    if (local_10 < iVar4 - local_c) {
      local_5c = local_10;
    }
    else {
      local_5c = FUN_0047a490();
      local_5c = local_5c - local_c;
    }
    local_10 = local_5c;
    iVar4 = FUN_0047a4b0();
    if (local_8 < iVar4 - local_1c) {
      local_60 = local_8;
    }
    else {
      local_60 = FUN_0047a4b0();
      local_60 = local_60 - local_1c;
    }
    local_8 = local_60;
    if (((int)local_14 < 0) || (0xf < (int)local_14)) {
      for (local_28 = local_c; local_28 < local_c + local_10; local_28 = local_28 + 1) {
        for (local_2c = local_1c; local_2c < local_1c + local_8; local_2c = local_2c + 1) {
          iVar6 = local_14 - 0x10;
          iVar4 = local_28;
          iVar5 = local_2c;
          FUN_004cde80(local_18);
          FUN_004cde80(iVar4);
          piVar2 = (int *)FUN_004ce990(iVar5);
          *piVar2 = iVar6;
        }
      }
    }
    else {
      for (local_20 = local_c; local_20 < local_c + local_10; local_20 = local_20 + 1) {
        for (local_24 = local_1c; local_24 < local_1c + local_8; local_24 = local_24 + 1) {
          iVar6 = local_14 + 1;
          iVar4 = local_20;
          iVar5 = local_24;
          FUN_004cde80(local_18);
          FUN_004cde80(iVar4);
          piVar2 = (int *)FUN_004ce990(iVar5);
          *piVar2 = iVar6 * 100000 + 0x115c;
        }
      }
    }
    if (local_c + -1 < 0) {
      local_64 = 0;
    }
    else {
      local_64 = local_c + -1;
    }
    local_30 = local_64;
    while( true ) {
      iVar4 = FUN_0047a490();
      if (iVar4 < local_c + 1 + local_10) {
        local_68 = FUN_0047a490();
      }
      else {
        local_68 = local_c + 1 + local_10;
      }
      if (local_68 <= local_30) break;
      if (local_1c + -1 < 0) {
        local_6c = 0;
      }
      else {
        local_6c = local_1c + -1;
      }
      local_34 = local_6c;
      while( true ) {
        iVar4 = FUN_0047a4b0();
        if (iVar4 < local_1c + 1 + local_8) {
          local_70 = FUN_0047a4b0();
        }
        else {
          local_70 = local_1c + 1 + local_8;
        }
        if (local_70 <= local_34) break;
        if ((((local_30 <= local_c) || (local_c + -1 + local_10 <= local_30)) ||
            (local_34 <= local_1c)) || (local_1c + -1 + local_8 <= local_34)) {
          iVar4 = local_30;
          iVar5 = local_34;
          FUN_004cde80(local_18);
          FUN_004cde80(iVar4);
          piVar2 = (int *)FUN_004ce990(iVar5);
          local_38 = *piVar2 / 100000;
          if (1 < local_38) {
            local_48 = 1;
            local_47[0] = 1;
            local_47[1] = 1;
            local_47[2] = 1;
            local_47[3] = 1;
            local_47[4] = 1;
            local_47[5] = 1;
            local_47[6] = 1;
            local_47[7] = 1;
            for (local_4c = -1; local_4c < 2; local_4c = local_4c + 1) {
              for (local_50 = -1; local_50 < 2; local_50 = local_50 + 1) {
                if (((local_30 + local_4c < 0) || (local_34 + local_50 < 0)) ||
                   ((DAT_00a17e7c <= local_30 + local_4c || (DAT_00a17e80 <= local_34 + local_50))))
                {
                  local_47[local_4c + (local_50 + 1) * 3] = 1;
                }
                else {
                  iVar5 = local_34 + local_50;
                  iVar4 = local_30 + local_4c;
                  FUN_004cde80(local_18);
                  FUN_004cde80(iVar4);
                  piVar2 = (int *)FUN_004ce990(iVar5);
                  if ((*piVar2 < (local_38 + 1) * 100000) && (local_38 * 100000 <= *piVar2)) {
                    local_47[local_4c + (local_50 + 1) * 3] = 1;
                  }
                  else {
                    local_47[local_4c + (local_50 + 1) * 3] = 0;
                  }
                }
              }
            }
            iVar7 = local_38 * 100000;
            iVar6 = FUN_00460560(&local_48);
            iVar4 = local_30;
            iVar5 = local_34;
            FUN_004cde80(local_18);
            FUN_004cde80(iVar4);
            piVar2 = (int *)FUN_004ce990(iVar5);
            *piVar2 = iVar7 + iVar6;
          }
        }
        local_34 = local_34 + 1;
      }
      local_30 = local_30 + 1;
    }
  }
  return 1;
}

