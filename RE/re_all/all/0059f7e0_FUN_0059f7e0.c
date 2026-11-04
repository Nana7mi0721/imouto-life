
undefined4 FUN_0059f7e0(uint param_1,int param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  int *piVar9;
  uint uVar10;
  uint uVar11;
  bool bVar12;
  int *local_40;
  int local_3c;
  int *local_38;
  int *local_34;
  int *local_30;
  int local_28;
  int local_24;
  int local_20;
  int *local_1c;
  int *local_18;
  
  local_18 = (int *)0x0;
  local_1c = (int *)0x0;
  local_30 = (int *)0x0;
  local_34 = (int *)0x0;
  local_40 = (int *)0x0;
  local_38 = (int *)0x0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_3c = 0;
  if (DAT_00a37dc8 == 0) {
    return 0;
  }
  if (-1 < param_2) {
    local_18 = &DAT_00e06948 + param_2;
    local_1c = (int *)(&DAT_00e90b68 + param_2 * 4);
  }
  if (-1 < (int)param_4) {
    uVar11 = (int)param_4 / 0x13b00 & 0x80000001;
    if ((int)uVar11 < 0) {
      uVar11 = (uVar11 - 1 | 0xfffffffe) + 1;
    }
    uVar1 = (int)param_4 / 0x150 & 0x80000001;
    if ((int)uVar1 < 0) {
      uVar1 = (uVar1 - 1 | 0xfffffffe) + 1;
    }
    uVar2 = (int)param_4 / 0xa8 & 0x80000001;
    if ((int)uVar2 < 0) {
      uVar2 = (uVar2 - 1 | 0xfffffffe) + 1;
    }
    iVar6 = ((int)param_4 / 2) % 0x54;
    uVar10 = param_4 & 0x80000001;
    if ((int)uVar10 < 0) {
      uVar10 = (uVar10 - 1 | 0xfffffffe) + 1;
    }
    uVar3 = (int)param_4 / 0x27600 & 0x80000001;
    if ((int)uVar3 < 0) {
      uVar3 = (uVar3 - 1 | 0xfffffffe) + 1;
    }
    if (uVar3 == 0) {
      iVar6 = (uVar2 + (uVar1 + (((int)param_4 / 0x3f00) % 5 + uVar11 * 5) * 2) * 2) * 0x54 + iVar6;
      local_30 = &DAT_00e26208 + uVar10 + iVar6 * 2;
      local_34 = (int *)(&DAT_00eb0428 + (uVar10 + iVar6 * 2) * 4);
    }
    else if (uVar3 == 1) {
      uVar3 = (int)param_4 / 0x1f80 & 0x80000001;
      if ((int)uVar3 < 0) {
        uVar3 = (uVar3 - 1 | 0xfffffffe) + 1;
      }
      uVar8 = (int)param_4 / 0x540 & 0x80000001;
      if ((int)uVar8 < 0) {
        uVar8 = (uVar8 - 1 | 0xfffffffe) + 1;
      }
      uVar4 = (int)param_4 / 0x2a0 & 0x80000001;
      if ((int)uVar4 < 0) {
        uVar4 = (uVar4 - 1 | 0xfffffffe) + 1;
      }
      iVar6 = (uVar2 + (uVar1 + (uVar4 + (uVar8 + (((int)param_4 / 0xa80) % 3 +
                                                  (uVar3 + uVar11 * 2) * 3) * 2) * 2) * 2) * 2) *
              0x54 + iVar6;
      local_30 = &DAT_00e06a08 + uVar10 + iVar6 * 2;
      local_34 = (int *)(&DAT_00e90c28 + (uVar10 + iVar6 * 2) * 4);
    }
  }
  piVar7 = (int *)0x0;
  if (-1 < (int)param_1) {
    local_28 = ((int)param_1 / 0xf00) % 3;
    iVar6 = ((int)param_1 / 0x140) % 3;
    uVar11 = (int)param_1 / 0x28 & 0x80000003;
    if ((int)uVar11 < 0) {
      uVar11 = (uVar11 - 1 | 0xfffffffc) + 1;
    }
    if (local_28 == 0) {
      local_24 = ((int)param_1 / 2) % 0x14;
      if (local_24 == 0) {
        local_38 = (int *)(&DAT_00eb6d88 + (uVar11 + iVar6 * 4) * 4);
        local_40 = &DAT_00e2cb68 + uVar11 + iVar6 * 4;
      }
      else {
        uVar1 = (int)param_1 / 0x780 & 0x80000001;
        if ((int)uVar1 < 0) {
          uVar1 = (uVar1 - 1 | 0xfffffffe) + 1;
        }
        uVar2 = (int)param_1 / 0x3c0 & 0x80000001;
        if ((int)uVar2 < 0) {
          uVar2 = (uVar2 - 1 | 0xfffffffe) + 1;
        }
        uVar10 = (int)param_1 / 0xa0 & 0x80000001;
        if ((int)uVar10 < 0) {
          uVar10 = (uVar10 - 1 | 0xfffffffe) + 1;
        }
        uVar3 = param_1 & 0x80000001;
        if ((int)uVar3 < 0) {
          uVar3 = (uVar3 - 1 | 0xfffffffe) + 1;
        }
        if (DAT_00ddb5f8 != 0) {
          uVar1 = 1;
        }
        iVar6 = local_24 + (uVar11 + (uVar10 + (iVar6 + (uVar2 + uVar1 * 2) * 3) * 2) * 4) * 0x14;
        local_38 = (int *)(&DAT_00eb6db8 + (uVar3 + iVar6 * 2) * 4);
        local_40 = &DAT_00e2cb98 + uVar3 + iVar6 * 2;
      }
    }
    else if (local_28 == 1) {
      local_40 = &DAT_00e2cb5c + iVar6;
      local_38 = (int *)(&DAT_00eb6d7c + iVar6 * 4);
    }
    else if (local_28 == 2) {
      iVar6 = uVar11 + iVar6 * 4;
      local_40 = &DAT_00e2cb2c + iVar6;
      local_38 = (int *)(&DAT_00eb6d4c + iVar6 * 4);
    }
  }
  piVar9 = piVar7;
  if (-1 < (int)param_3) {
    iVar6 = ((int)param_3 / 0x38400) % 9;
    local_20 = ((int)param_3 / 0x12c00) % 3;
    uVar11 = (int)param_3 / 0x9600 & 0x80000001;
    if ((int)uVar11 < 0) {
      uVar11 = (uVar11 - 1 | 0xfffffffe) + 1;
    }
    uVar1 = (int)param_3 / 0x4b00 & 0x80000001;
    if ((int)uVar1 < 0) {
      uVar1 = (uVar1 - 1 | 0xfffffffe) + 1;
    }
    uVar2 = (int)param_3 / 0x28 & 0x80000001;
    if ((int)uVar2 < 0) {
      uVar2 = (uVar2 - 1 | 0xfffffffe) + 1;
    }
    uVar10 = (int)param_3 / 0x14 & 0x80000001;
    if ((int)uVar10 < 0) {
      uVar10 = (uVar10 - 1 | 0xfffffffe) + 1;
    }
    local_3c = ((int)param_3 / 2) % 10;
    uVar3 = param_3 & 0x80000001;
    if ((int)uVar3 < 0) {
      uVar3 = (uVar3 - 1 | 0xfffffffe) + 1;
    }
    if (DAT_00ddb5fc != 0) {
      uVar11 = 1;
    }
    if (iVar6 - 3U < 6) {
      piVar7 = &DAT_00e2cb08 + iVar6;
      piVar9 = (int *)(&DAT_00eb6d28 + iVar6 * 4);
    }
    else if (local_20 == 0) {
      uVar8 = (int)param_3 / 0x780 & 0x80000001;
      bVar12 = uVar8 == 0;
      if ((int)uVar8 < 0) {
        bVar12 = (uVar8 - 1 | 0xfffffffe) == 0xffffffff;
      }
      if (bVar12) {
        iVar6 = ((int)param_3 / 0xf00) % 5;
        if (local_3c == 0) {
          piVar7 = &DAT_00e307e0 + iVar6;
          piVar9 = (int *)(&DAT_00ebaa00 + iVar6 * 4);
        }
        else {
          iVar6 = uVar3 + (local_3c +
                          (uVar10 + (uVar2 + (iVar6 + (uVar1 + uVar11 * 2) * 5) * 2) * 2) * 10) * 2;
          piVar7 = &DAT_00e37ff4 + iVar6;
          piVar9 = (int *)(&DAT_00ec2214 + iVar6 * 4);
        }
      }
      else {
        uVar8 = (int)param_3 / 0x3c0 & 0x80000001;
        if ((int)uVar8 < 0) {
          uVar8 = (uVar8 - 1 | 0xfffffffe) + 1;
        }
        uVar4 = (int)param_3 / 0xa0 & 0x80000001;
        if ((int)uVar4 < 0) {
          uVar4 = (uVar4 - 1 | 0xfffffffe) + 1;
        }
        if (local_3c == 0) {
          piVar7 = &DAT_00e307d0 + uVar4 + uVar8 * 2;
          piVar9 = (int *)(&DAT_00eba9f0 + (uVar4 + uVar8 * 2) * 4);
        }
        else {
          uVar5 = (int)param_3 / 0x50 & 0x80000001;
          if ((int)uVar5 < 0) {
            uVar5 = (uVar5 - 1 | 0xfffffffe) + 1;
          }
          iVar6 = uVar3 + (local_3c +
                          (uVar10 + (uVar2 + (uVar5 + (uVar4 + (((int)param_3 / 0x140) % 3 +
                                                               (uVar8 + (uVar1 + uVar11 * 2) * 2) *
                                                               3) * 2) * 2) * 2) * 2) * 10) * 2;
          piVar7 = &DAT_00e307f4 + iVar6;
          piVar9 = (int *)(&DAT_00ebaa14 + iVar6 * 4);
        }
      }
    }
    else if (local_20 == 1) {
      uVar11 = (int)param_3 / 0x780 & 0x80000001;
      if ((int)uVar11 < 0) {
        uVar11 = (uVar11 - 1 | 0xfffffffe) + 1;
      }
      if (uVar11 == 0) {
        piVar7 = &DAT_00e307cc;
        piVar9 = (int *)&DAT_00eba9ec;
      }
      else {
        uVar11 = (int)param_3 / 0x3c0 & 0x80000001;
        if ((int)uVar11 < 0) {
          uVar11 = (uVar11 - 1 | 0xfffffffe) + 1;
        }
        uVar1 = (int)param_3 / 0xa0 & 0x80000001;
        if ((int)uVar1 < 0) {
          uVar1 = (uVar1 - 1 | 0xfffffffe) + 1;
        }
        iVar6 = uVar1 + (((int)param_3 / 0x140) % 3 + uVar11 * 3) * 2;
        piVar7 = &DAT_00e3079c + iVar6;
        piVar9 = (int *)(&DAT_00eba9bc + iVar6 * 4);
      }
    }
    else if (local_20 == 2) {
      piVar7 = &DAT_00e30798;
      piVar9 = (int *)&DAT_00eba9b8;
    }
    else {
      piVar7 = (int *)0x0;
      piVar9 = piVar7;
    }
  }
  if (((((((param_2 < 0) || (DAT_00ddb5f8 == 0)) || (local_28 != 0)) ||
        ((local_24 == 0 || (*local_1c == 0)))) ||
       (((int)param_4 < 0 || ((DAT_00ddb5fc == 0 || (local_20 != 0)))))) || (local_3c == 0)) ||
     (bVar12 = true, *local_34 == 0)) {
    bVar12 = false;
  }
  if (((DAT_00e06944 == 0) && (DAT_00ddb364 == 0)) || (!bVar12)) {
    if ((int)param_1 < 0) {
LAB_0059fffe:
      if ((int)param_3 < 0) {
        return 1;
      }
      if ((*piVar7 != 0) || ((*piVar9 != 0 && (iVar6 = FUN_005d3d00(*piVar9,piVar7), iVar6 == 0))))
      {
        iVar6 = *piVar7;
        goto LAB_005a008e;
      }
    }
    else if ((*local_40 != 0) ||
            ((*local_38 != 0 && (iVar6 = FUN_005d3c10(*local_38,local_40), iVar6 == 0)))) {
      FUN_0059b720(*local_40,0);
      goto LAB_0059fffe;
    }
    if (!bVar12) {
      return 0;
    }
  }
  if (-1 < (int)param_1) {
    if ((*local_18 == 0) && (iVar6 = FUN_005d3c10(*local_1c,local_18), iVar6 != 0)) {
      return 0;
    }
    FUN_0059b720(*local_18,0);
  }
  if ((int)param_3 < 0) {
    return 1;
  }
  if ((*local_30 == 0) && (iVar6 = FUN_005d3d00(*local_34,local_30), iVar6 != 0)) {
    return 0;
  }
  iVar6 = *local_30;
LAB_005a008e:
  FUN_0059b820(iVar6,0);
  return 1;
}

