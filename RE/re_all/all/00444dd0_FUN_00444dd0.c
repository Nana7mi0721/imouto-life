
/* WARNING: Removing unreachable block (ram,0x004454e4) */
/* WARNING: Removing unreachable block (ram,0x00445500) */
/* WARNING: Removing unreachable block (ram,0x004454f7) */
/* WARNING: Removing unreachable block (ram,0x0044551c) */
/* WARNING: Removing unreachable block (ram,0x00445542) */
/* WARNING: Removing unreachable block (ram,0x00445539) */
/* WARNING: Removing unreachable block (ram,0x0044555e) */
/* WARNING: Removing unreachable block (ram,0x00445579) */
/* WARNING: Removing unreachable block (ram,0x0044558c) */
/* WARNING: Removing unreachable block (ram,0x004455af) */
/* WARNING: Removing unreachable block (ram,0x004455b3) */
/* WARNING: Removing unreachable block (ram,0x004455d0) */
/* WARNING: Removing unreachable block (ram,0x00445603) */
/* WARNING: Removing unreachable block (ram,0x00445641) */
/* WARNING: Removing unreachable block (ram,0x0044564c) */
/* WARNING: Removing unreachable block (ram,0x0044567d) */
/* WARNING: Removing unreachable block (ram,0x004456b0) */
/* WARNING: Removing unreachable block (ram,0x004456b6) */
/* WARNING: Removing unreachable block (ram,0x004456e9) */
/* WARNING: Removing unreachable block (ram,0x0044571a) */
/* WARNING: Removing unreachable block (ram,0x00445638) */
/* WARNING: Removing unreachable block (ram,0x0044571e) */
/* WARNING: Removing unreachable block (ram,0x0044572a) */
/* WARNING: Removing unreachable block (ram,0x00445764) */
/* WARNING: Removing unreachable block (ram,0x00445799) */
/* WARNING: Removing unreachable block (ram,0x004457a1) */
/* WARNING: Removing unreachable block (ram,0x004457bd) */
/* WARNING: Removing unreachable block (ram,0x004457d9) */
/* WARNING: Removing unreachable block (ram,0x00445570) */

undefined1 __thiscall FUN_00444dd0(int param_1,int param_2)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_24;
  uint local_18;
  int local_14;
  undefined1 local_e;
  uint local_c;
  uint local_8;
  
  local_e = 0;
  cVar2 = FUN_00486cd0();
  if (cVar2 == '\0') {
    if ((*(short *)(param_1 + 0x48) < 1) || ((int)*(short *)(param_1 + 0x48) % 3 != 0)) {
      if ((*(short *)(param_1 + 0x48) + 2) % 3 == 0) {
        local_3c = -*(int *)(param_1 + 0xb4);
      }
      else {
        local_3c = 0;
      }
      local_38 = local_3c;
    }
    else {
      local_38 = *(int *)(param_1 + 0xb4);
    }
    local_c = *(int *)(param_1 + 0x28) + local_38;
    if ((*(short *)(param_1 + 0x48) < 1) ||
       ((int)((int)*(short *)(param_1 + 0x48) + ((int)*(short *)(param_1 + 0x48) >> 0x1f & 3U)) >> 2
        != 0)) {
      if ((int)*(short *)(param_1 + 0x48) / 7 == 1) {
        if (*(char *)(param_1 + 0xb9) == '\0') {
          local_44 = -*(int *)(param_1 + 0xb4);
        }
        else {
          local_44 = -2;
        }
        local_48 = local_44;
      }
      else {
        local_48 = 0;
      }
      local_40 = local_48;
    }
    else {
      local_40 = *(int *)(param_1 + 0xb4);
    }
    local_8 = *(int *)(param_1 + 0x2c) + local_40;
    iVar3 = FUN_0047a490();
    if ((iVar3 * 2 + -1 <= (int)local_c) && (DAT_00a180f4 != '\0')) {
      iVar3 = FUN_0047a490();
      local_c = local_c - (iVar3 * 2 + -1);
    }
    iVar3 = FUN_0047a4b0();
    if ((iVar3 * 2 + -1 <= (int)local_8) && (DAT_00a180f5 != '\0')) {
      iVar3 = FUN_0047a4b0();
      local_8 = local_8 - (iVar3 * 2 + -1);
    }
    if ((0x7fffffff < local_c) && (DAT_00a180f4 != '\0')) {
      iVar3 = FUN_0047a490();
      local_c = local_c + iVar3 * 2;
    }
    if ((0x7fffffff < local_8) && (DAT_00a180f5 != '\0')) {
      iVar3 = FUN_0047a4b0();
      local_8 = local_8 + iVar3 * 2;
    }
    for (local_14 = 0; iVar3 = FUN_004d29a0(), local_14 < iVar3; local_14 = local_14 + 1) {
      bVar1 = false;
      local_18 = (uint)DAT_00a144f1;
      if ((*(short *)(param_1 + 0x48) < 4) || (6 < *(short *)(param_1 + 0x48))) {
        local_18 = 0;
      }
      iVar3 = FUN_004d2a00(local_14);
      cVar2 = *(char *)(param_2 + *(int *)(iVar3 + 0x1e8));
      iVar3 = FUN_004d2a00(local_14);
      if (*(char *)(iVar3 + 0xb9) == '\0') {
LAB_004450a1:
        iVar3 = FUN_004d2a00(local_14);
        uVar6 = 0;
        uVar5 = 1;
        FUN_004d2a00(local_14);
        iVar4 = FUN_004789a0(uVar5,uVar6);
        if ((int)((local_8 - iVar4) - local_18) <= *(int *)(iVar3 + 0x2c)) {
          iVar3 = FUN_004d2a00(local_14);
          uVar6 = 1;
          uVar5 = 1;
          FUN_004d2a00(local_14);
          iVar4 = FUN_004789a0(uVar5,uVar6);
          if (*(int *)(iVar3 + 0x2c) <= (int)(iVar4 + local_8)) {
            bVar1 = true;
          }
        }
      }
      else {
        iVar3 = FUN_004d2a00(local_14);
        uVar6 = 0;
        uVar5 = 1;
        FUN_004d2a00(local_14);
        iVar4 = FUN_004789a0(uVar5,uVar6);
        if (*(int *)(iVar3 + 0x2c) < (int)((local_8 - iVar4) - local_18)) goto LAB_004450a1;
        iVar3 = FUN_004d2a00(local_14);
        uVar6 = 1;
        uVar5 = 1;
        FUN_004d2a00(local_14);
        iVar4 = FUN_004789a0(uVar5,uVar6);
        if ((int)(local_8 + 1 + iVar4) < *(int *)(iVar3 + 0x2c)) goto LAB_004450a1;
        bVar1 = true;
      }
      if (cVar2 != '\0') {
        iVar3 = FUN_004d2a00(local_14);
        uVar6 = 0;
        uVar5 = 0;
        FUN_004d2a00(local_14);
        iVar4 = FUN_004789a0(uVar5,uVar6);
        if ((int)((local_c - 1) - iVar4) <= *(int *)(iVar3 + 0x28)) {
          iVar3 = FUN_004d2a00(local_14);
          uVar6 = 0;
          uVar5 = 0;
          FUN_004d2a00(local_14);
          iVar4 = FUN_004789a0(uVar5,uVar6);
          if ((*(int *)(iVar3 + 0x28) <= (int)(local_c + 1 + iVar4)) && (bVar1)) {
            FUN_004d2a00(local_14);
            cVar2 = FUN_00478410();
            if (cVar2 == '\0') {
              FUN_004d2a00(local_14);
              cVar2 = FUN_00446ea0();
              if (cVar2 == '\0') {
                uVar5 = 0xffffffff;
                FUN_004d2a00(local_14);
                FUN_004799d0(uVar5);
                return 1;
              }
            }
          }
        }
      }
    }
    cVar2 = FUN_0044ab10(local_c,local_8);
    if (cVar2 != '\0') {
      if ((int)*(short *)(param_1 + 0x48) % 3 == 0) {
        local_4c = 2;
      }
      else {
        if ((*(short *)(param_1 + 0x48) + 2) % 3 == 0) {
          local_50 = -2;
        }
        else {
          local_50 = 0;
        }
        local_4c = local_50;
      }
      if ((int)((int)*(short *)(param_1 + 0x48) + ((int)*(short *)(param_1 + 0x48) >> 0x1f & 3U)) >>
          2 == 0) {
        local_54 = 2;
      }
      else {
        if ((int)*(short *)(param_1 + 0x48) / 7 == 1) {
          local_58 = -2;
        }
        else {
          local_58 = 0;
        }
        local_54 = local_58;
      }
      local_54 = local_8 + local_54;
      for (local_24 = 0; iVar3 = FUN_004d29a0(), local_24 < iVar3; local_24 = local_24 + 1) {
        iVar3 = FUN_004d2a00(local_24);
        cVar2 = *(char *)(param_2 + *(int *)(iVar3 + 0x1e8));
        bVar1 = false;
        iVar3 = FUN_004d2a00(local_24);
        if (*(char *)(iVar3 + 0xb9) == '\0') {
LAB_00445397:
          iVar3 = FUN_004d2a00(local_24);
          uVar6 = 0;
          uVar5 = 1;
          FUN_004d2a00(local_24);
          iVar4 = FUN_004789a0(uVar5,uVar6);
          if (local_54 - iVar4 <= *(int *)(iVar3 + 0x2c)) {
            iVar3 = FUN_004d2a00(local_24);
            uVar6 = 1;
            uVar5 = 1;
            FUN_004d2a00(local_24);
            iVar4 = FUN_004789a0(uVar5,uVar6);
            if (*(int *)(iVar3 + 0x2c) <= iVar4 + local_54) {
              bVar1 = true;
            }
          }
        }
        else {
          iVar3 = FUN_004d2a00(local_24);
          uVar6 = 0;
          uVar5 = 1;
          FUN_004d2a00(local_24);
          iVar4 = FUN_004789a0(uVar5,uVar6);
          if (*(int *)(iVar3 + 0x2c) < local_54 - iVar4) goto LAB_00445397;
          iVar3 = FUN_004d2a00(local_24);
          uVar6 = 1;
          uVar5 = 1;
          FUN_004d2a00(local_24);
          iVar4 = FUN_004789a0(uVar5,uVar6);
          if (local_54 + 1 + iVar4 < *(int *)(iVar3 + 0x2c)) goto LAB_00445397;
          bVar1 = true;
        }
        if (cVar2 != '\0') {
          iVar3 = FUN_004d2a00(local_24);
          uVar6 = 0;
          uVar5 = 0;
          FUN_004d2a00(local_24);
          iVar4 = FUN_004789a0(uVar5,uVar6);
          if ((int)((local_c + local_4c + -1) - iVar4) <= *(int *)(iVar3 + 0x28)) {
            iVar3 = FUN_004d2a00(local_24);
            uVar6 = 0;
            uVar5 = 0;
            FUN_004d2a00(local_24);
            iVar4 = FUN_004789a0(uVar5,uVar6);
            if ((*(int *)(iVar3 + 0x28) <= (int)(local_c + local_4c + 1 + iVar4)) && (bVar1)) {
              FUN_004d2a00(local_24);
              cVar2 = FUN_00478410();
              if (cVar2 == '\0') {
                FUN_004d2a00(local_24);
                cVar2 = FUN_00446ea0();
                if (cVar2 == '\0') {
                  uVar5 = 0xffffffff;
                  FUN_004d2a00(local_24);
                  FUN_004799d0(uVar5);
                  local_e = 1;
                  break;
                }
              }
            }
          }
        }
      }
    }
  }
  else {
    local_e = 0;
  }
  return local_e;
}

