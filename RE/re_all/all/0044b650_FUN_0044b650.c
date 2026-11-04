
void __fastcall FUN_0044b650(int param_1)

{
  int iVar1;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_8;
  
  DAT_00a1434c = 0;
  if (DAT_00a1809c != '\0') {
    FUN_00449ee0();
  }
  if (0 < *(int *)(param_1 + 0x166c)) {
    if (*(int *)(param_1 + 0x1664) == 4) {
      if (-*(int *)(param_1 + 0x1674) == *(int *)(param_1 + 0x166c) ||
          -*(int *)(param_1 + 0x166c) < *(int *)(param_1 + 0x1674)) {
        local_14 = *(int *)(param_1 + 0x1674);
      }
      else {
        local_14 = -*(int *)(param_1 + 0x166c);
      }
      if (local_14 < *(int *)(param_1 + 0x166c)) {
        if (-*(int *)(param_1 + 0x1674) == *(int *)(param_1 + 0x166c) ||
            -*(int *)(param_1 + 0x166c) < *(int *)(param_1 + 0x1674)) {
          local_18 = *(int *)(param_1 + 0x1674);
        }
        else {
          local_18 = -*(int *)(param_1 + 0x166c);
        }
        local_1c = local_18;
      }
      else {
        local_1c = *(int *)(param_1 + 0x166c);
      }
      FUN_0044a0d0(local_1c);
    }
    else if (*(int *)(param_1 + 0x1664) == 6) {
      if (-*(int *)(param_1 + 0x1674) == *(int *)(param_1 + 0x166c) ||
          -*(int *)(param_1 + 0x166c) < *(int *)(param_1 + 0x1674)) {
        local_20 = *(int *)(param_1 + 0x1674);
      }
      else {
        local_20 = -*(int *)(param_1 + 0x166c);
      }
      if (local_20 < *(int *)(param_1 + 0x166c)) {
        if (-*(int *)(param_1 + 0x1674) == *(int *)(param_1 + 0x166c) ||
            -*(int *)(param_1 + 0x166c) < *(int *)(param_1 + 0x1674)) {
          local_24 = *(int *)(param_1 + 0x1674);
        }
        else {
          local_24 = -*(int *)(param_1 + 0x166c);
        }
        local_28 = local_24;
      }
      else {
        local_28 = *(int *)(param_1 + 0x166c);
      }
      FUN_0044a170(local_28);
    }
    if (*(int *)(param_1 + 0x166c) - *(int *)(param_1 + 0x1674) < 0) {
      local_2c = 0;
    }
    else {
      local_2c = *(int *)(param_1 + 0x166c) - *(int *)(param_1 + 0x1674);
    }
    *(int *)(param_1 + 0x166c) = local_2c;
  }
  if (0 < *(int *)(param_1 + 0x1670)) {
    if (*(int *)(param_1 + 0x1668) == 2) {
      if (-*(int *)(param_1 + 0x1678) == *(int *)(param_1 + 0x1670) ||
          -*(int *)(param_1 + 0x1670) < *(int *)(param_1 + 0x1678)) {
        local_34 = *(int *)(param_1 + 0x1678);
      }
      else {
        local_34 = -*(int *)(param_1 + 0x1670);
      }
      if (local_34 < *(int *)(param_1 + 0x1670)) {
        if (-*(int *)(param_1 + 0x1678) == *(int *)(param_1 + 0x1670) ||
            -*(int *)(param_1 + 0x1670) < *(int *)(param_1 + 0x1678)) {
          local_38 = *(int *)(param_1 + 0x1678);
        }
        else {
          local_38 = -*(int *)(param_1 + 0x1670);
        }
        local_3c = local_38;
      }
      else {
        local_3c = *(int *)(param_1 + 0x1670);
      }
      FUN_00449f90(local_3c);
    }
    else if (*(int *)(param_1 + 0x1668) == 8) {
      if (-*(int *)(param_1 + 0x1678) == *(int *)(param_1 + 0x1670) ||
          -*(int *)(param_1 + 0x1670) < *(int *)(param_1 + 0x1678)) {
        local_40 = *(int *)(param_1 + 0x1678);
      }
      else {
        local_40 = -*(int *)(param_1 + 0x1670);
      }
      if (local_40 < *(int *)(param_1 + 0x1670)) {
        if (-*(int *)(param_1 + 0x1678) == *(int *)(param_1 + 0x1670) ||
            -*(int *)(param_1 + 0x1670) < *(int *)(param_1 + 0x1678)) {
          local_44 = *(int *)(param_1 + 0x1678);
        }
        else {
          local_44 = -*(int *)(param_1 + 0x1670);
        }
        local_48 = local_44;
      }
      else {
        local_48 = *(int *)(param_1 + 0x1670);
      }
      FUN_0044a2b0(local_48);
    }
    if (*(int *)(param_1 + 0x1670) - *(int *)(param_1 + 0x1678) < 0) {
      local_4c = 0;
    }
    else {
      local_4c = *(int *)(param_1 + 0x1670) - *(int *)(param_1 + 0x1678);
    }
    *(int *)(param_1 + 0x1670) = local_4c;
  }
  FUN_0044b0a0();
  iVar1 = (int)*DAT_00a16674 * *(int *)(param_1 + 0x18bc);
  iVar1 = iVar1 + (iVar1 >> 0x1f & 0x1fU);
  *(int *)(param_1 + 0x1898) = (int)((iVar1 >> 5) + (iVar1 >> 0x1f & 0x3fU)) >> 6;
  iVar1 = (int)*DAT_00a16674 * *(int *)(param_1 + 0x18c0);
  iVar1 = iVar1 + (iVar1 >> 0x1f & 0x1fU);
  *(int *)(param_1 + 0x189c) = (int)((iVar1 >> 5) + (iVar1 >> 0x1f & 0x3fU)) >> 6;
  if (*(int *)(param_1 + 0x1908) < 1) {
    *(undefined4 *)(param_1 + 0x190c) = *(undefined4 *)(param_1 + 0x18ec);
    *(undefined4 *)(param_1 + 0x1910) = *(undefined4 *)(param_1 + 0x18f4);
    *(undefined4 *)(param_1 + 0x1914) = *(undefined4 *)(param_1 + 0x18fc);
  }
  else {
    *(int *)(param_1 + 0x1908) = *(int *)(param_1 + 0x1908) + -1;
    if (*(int *)(param_1 + 0x1908) < 1) {
      *(undefined4 *)(param_1 + 0x1900) = *(undefined4 *)(param_1 + 0x18fc);
    }
    *(int *)(param_1 + 0x190c) =
         *(int *)(param_1 + 0x18ec) -
         ((*(int *)(param_1 + 0x18ec) - *(int *)(param_1 + 0x18f0)) * *(int *)(param_1 + 0x1908)) /
         *(int *)(param_1 + 0x1904);
    *(int *)(param_1 + 0x1910) =
         *(int *)(param_1 + 0x18f4) -
         ((*(int *)(param_1 + 0x18f4) - *(int *)(param_1 + 0x18f8)) * *(int *)(param_1 + 0x1908)) /
         *(int *)(param_1 + 0x1904);
    *(int *)(param_1 + 0x1914) =
         *(int *)(param_1 + 0x18fc) -
         ((*(int *)(param_1 + 0x18fc) - *(int *)(param_1 + 0x1900)) * *(int *)(param_1 + 0x1908)) /
         *(int *)(param_1 + 0x1904);
  }
  for (local_8 = 0; iVar1 = FUN_004d29a0(), local_8 < iVar1; local_8 = local_8 + 1) {
    FUN_004d2a00(local_8);
    FUN_004474a0();
  }
  *(int *)(param_1 + 0x1890) = (*(int *)(param_1 + 0x1890) + 1) % 2400000;
  return;
}

