
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Type propagation algorithm not settling */

int FUN_00579b50(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                undefined4 param_7,uint *param_8)

{
  undefined8 uVar1;
  undefined1 *puVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  bool bVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  int local_1248;
  uint local_1240;
  undefined1 *local_1238;
  uint local_1234;
  undefined4 local_1230;
  undefined4 local_122c;
  undefined1 *local_1228;
  int *local_1224;
  undefined4 local_1218;
  undefined4 local_1214;
  undefined4 local_1210;
  int local_120c;
  int *local_1208;
  undefined1 local_1200 [512];
  int local_1000 [1023];
  undefined4 uStack_4;
  
  uStack_4 = 0x579b5a;
  local_1208 = (int *)0x0;
  iVar5 = FUN_005739b0(param_7,param_1,0);
  uVar7 = iVar5 + 0x40;
  if (uVar7 < 0x1001) {
    local_1224 = local_1000;
  }
  else {
    local_1224 = (int *)FUN_0056e030(uVar7,"..\\..\\..\\..\\Source\\Library\\Main\\DxChar.cpp",
                                     0x191c);
    if (local_1224 == (int *)0x0) {
      return -1;
    }
    local_1208 = local_1224;
  }
  FUN_0056d380(local_1224,0,uVar7);
  FUN_005739b0(param_7,param_1,local_1224);
  iVar6 = FUN_00572ac0(param_1);
  param_6 = iVar6 * param_6;
  iVar5 = 0;
  uVar7 = FUN_00573310(0,param_1,param_5,param_6);
  if (uVar7 == 0) {
    return 0;
  }
  iVar12 = 0;
  iVar8 = *local_1224;
joined_r0x00579c1a:
  if (iVar8 == 0) {
LAB_0057a00c:
    FUN_00573310(0,param_1,iVar5 + param_5,param_6 - iVar5);
    if (local_1208 != (int *)0x0) {
      FUN_0056e1d0(local_1208);
    }
    return iVar5 / iVar6;
  }
  if (local_1224[iVar12] != 0x25) {
LAB_0057a4c2:
    iVar8 = FUN_00573310(local_1224[iVar12],param_1,iVar5 + param_5,param_6 - iVar5);
    if ((iVar8 != 0) && (iVar8 + uVar7 <= (uint)(param_6 - iVar5))) {
      iVar12 = iVar12 + 1;
joined_r0x0057a2bd:
      iVar5 = iVar5 + iVar8;
      if (uVar7 < (uint)(param_6 - iVar5)) goto switchD_00579ecf_caseD_f;
    }
    goto LAB_0057a00c;
  }
  if (local_1224[iVar12 + 1] != 0x25) {
    if (local_1224[iVar12 + 1] != 0x25) {
      local_1238 = (undefined1 *)0x0;
      local_1230 = 0;
      local_1214 = 0;
      local_1218 = 0;
      local_122c = 0;
      bVar14 = false;
      local_1240 = 0xffffffff;
      bVar3 = false;
      local_1234 = 0xffffffff;
      bVar4 = false;
      local_1248 = -1;
switchD_00579d1b_caseD_21:
      iVar12 = iVar12 + 1;
switchD_00579e24_caseD_4a:
      iVar8 = local_1224[iVar12];
      switch(iVar8) {
      case 0x20:
      case 0x23:
      case 0x2b:
      case 0x2d:
        goto switchD_00579cfd_caseD_20;
      default:
        goto switchD_00579cfd_caseD_21;
      case 0x2a:
        if (bVar4) goto switchD_00579cfd_caseD_21;
        iVar12 = iVar12 + 1;
        if (bVar3) {
          local_1234 = *param_8;
          param_8 = param_8 + 1;
        }
        else {
          local_1240 = *param_8;
          param_8 = param_8 + 1;
        }
        goto switchD_00579e24_caseD_4a;
      case 0x2e:
        if (bVar3) goto switchD_00579cfd_caseD_21;
        bVar14 = true;
        bVar3 = true;
        local_1234 = 0;
        iVar12 = iVar12 + 1;
        goto switchD_00579e24_caseD_4a;
      case 0x30:
      case 0x31:
      case 0x32:
      case 0x33:
      case 0x34:
      case 0x35:
      case 0x36:
      case 0x37:
      case 0x38:
      case 0x39:
        if (bVar4) goto switchD_00579cfd_caseD_21;
        if (bVar3) {
          local_1234 = FUN_00577b70();
          iVar12 = iVar12 + local_120c;
        }
        else {
          if ((!bVar14) && (iVar8 == 0x30)) {
            local_1230 = 1;
            goto switchD_00579d1b_caseD_21;
          }
          bVar14 = true;
          local_1240 = FUN_00577b70();
          iVar12 = iVar12 + local_120c;
        }
        goto switchD_00579e24_caseD_4a;
      case 0x41:
        iVar8 = 0xe;
        break;
      case 0x43:
        iVar8 = 1;
        break;
      case 0x45:
        iVar8 = 9;
        break;
      case 0x47:
        iVar8 = 0xc;
        break;
      case 0x49:
      case 0x68:
      case 0x6c:
      case 0x77:
        goto switchD_00579cfd_caseD_49;
      case 0x53:
        iVar8 = 0x12;
        break;
      case 0x58:
        iVar8 = 7;
        break;
      case 0x5a:
        iVar12 = iVar12 + 1;
        goto switchD_00579cfd_caseD_21;
      case 0x61:
        iVar8 = 0xd;
        break;
      case 99:
        iVar8 = 0;
        break;
      case 100:
        iVar8 = 2;
        break;
      case 0x65:
        iVar8 = 8;
        break;
      case 0x66:
        iVar8 = 10;
        break;
      case 0x67:
        iVar8 = 0xb;
        break;
      case 0x69:
        iVar8 = 3;
        break;
      case 0x6e:
        iVar8 = 0xf;
        break;
      case 0x6f:
        iVar8 = 4;
        break;
      case 0x70:
        iVar8 = 0x10;
        break;
      case 0x73:
        iVar8 = 0x11;
        break;
      case 0x75:
        iVar8 = 5;
        break;
      case 0x78:
        iVar8 = 6;
      }
      iVar12 = iVar12 + 1;
                    /* WARNING (jumptable): Sanity check requires truncation of jumptable */
                    /* WARNING: Could not find normalized switch variable to match jumptable */
      switch(iVar8) {
      case 0:
      case 1:
        uVar13 = 0;
        iVar10 = param_3;
        if (iVar8 == 0) {
          if (param_2 != 0) goto LAB_0057a07c;
        }
        else if (param_2 == 0) {
LAB_0057a07c:
          iVar10 = param_4;
        }
        iVar8 = FUN_00572ac0(iVar10);
        if (iVar8 == 1) {
          uVar13 = (uint)(byte)*param_8;
LAB_0057a0c5:
          param_8 = param_8 + 1;
        }
        else {
          if (iVar8 == 2) {
            uVar13 = (uint)(ushort)*param_8;
            goto LAB_0057a0c5;
          }
          if (iVar8 == 4) {
            uVar13 = *param_8;
            goto LAB_0057a0c5;
          }
        }
        if (iVar10 != param_1) {
          uVar13 = FUN_005736c0(uVar13,iVar10,param_1);
        }
        iVar8 = FUN_00579a40(uVar13,local_1230,local_122c,local_1240,iVar5 + param_5,param_1);
        goto joined_r0x0057a2bd;
      case 2:
      case 3:
        if (local_1248 == 0) {
          uVar9 = (uint)(short)(ushort)*param_8;
LAB_0057a159:
          param_8 = param_8 + 1;
          uVar13 = (int)uVar9 >> 0x1f;
        }
        else {
          if ((local_1248 != 2) && (local_1248 != 6)) {
            uVar9 = *param_8;
            goto LAB_0057a159;
          }
          uVar9 = *param_8;
          uVar13 = param_8[1];
          param_8 = param_8 + 2;
        }
        uVar15 = 0;
        if (((int)uVar13 < 1) && ((int)uVar13 < 0)) {
          bVar14 = uVar9 != 0;
          uVar9 = -uVar9;
          uVar15 = 1;
          uVar13 = -(uVar13 + bVar14);
        }
        uVar18 = 0;
        uVar17 = 10;
        uVar16 = 1;
        break;
      case 4:
      case 5:
      case 6:
      case 7:
        switch(iVar8) {
        case 4:
          local_1210 = 8;
          break;
        case 5:
          local_1210 = 10;
          break;
        case 6:
        case 7:
          local_1210 = 0x10;
        }
        switch(local_1248) {
        case 0:
          uVar9 = (uint)(ushort)*param_8;
          uVar13 = 0;
          param_8 = param_8 + 1;
          goto LAB_0057a258;
        default:
          uVar9 = *param_8;
          param_8 = param_8 + 1;
          uVar13 = 0;
          break;
        case 2:
        case 6:
          uVar9 = *param_8;
          uVar13 = param_8[1];
          param_8 = param_8 + 2;
        }
LAB_0057a258:
        iVar8 = FUN_00578f50(uVar9,uVar13,0,0,local_1210,local_1238,local_1230,local_122c,local_1218
                             ,local_1214,local_1240,local_1234,iVar8 == 7,iVar5 + param_5,
                             param_6 - iVar5,param_1);
        goto joined_r0x0057a2bd;
      default:
        uVar1 = *(undefined8 *)param_8;
        param_8 = param_8 + 2;
        iVar8 = FUN_00578920(uVar1,iVar8,local_1230,local_122c,local_1218,local_1214,local_1240,
                             iVar5 + param_5,param_6 - iVar5,param_1);
        goto joined_r0x0057a2bd;
      case 0xf:
        goto switchD_00579ecf_caseD_f;
      case 0x10:
        uVar9 = *param_8;
        param_8 = param_8 + 1;
        uVar18 = 1;
        local_1234 = 8;
        uVar17 = 0x10;
        uVar16 = 0;
        uVar15 = 0;
        uVar13 = (int)uVar9 >> 0x1f;
        break;
      case 0x11:
      case 0x12:
        puVar2 = (undefined1 *)*param_8;
        param_8 = param_8 + 1;
        local_1238 = (undefined1 *)0x0;
        if (puVar2 == (undefined1 *)0x0) goto switchD_00579ecf_caseD_f;
        iVar10 = param_3;
        if (iVar8 == 0x11) {
          if (param_2 != 0) goto LAB_0057a3d5;
        }
        else if (param_2 == 0) {
LAB_0057a3d5:
          iVar10 = param_4;
        }
        local_1228 = puVar2;
        if (iVar10 != param_1) {
          iVar8 = FUN_005773c0(iVar10,puVar2);
          iVar11 = FUN_00572ac0(iVar10);
          uVar13 = (iVar8 + 1) * iVar11;
          if (uVar13 < 0x201) {
            local_1228 = local_1200;
          }
          else {
            local_1238 = (undefined1 *)
                         FUN_0056e030(uVar13,"..\\..\\..\\..\\Source\\Library\\Main\\DxChar.cpp",
                                      0x1b32);
            if (local_1238 == (undefined1 *)0x0) goto switchD_00579ecf_caseD_f;
            local_1228 = local_1238;
          }
          FUN_005764b0(puVar2,0xffffffff,iVar10,local_1228,uVar13,param_1);
        }
        if (local_1228 == (undefined1 *)0x0) goto switchD_00579ecf_caseD_f;
        iVar8 = FUN_005797d0(local_1228,local_1230,local_122c,local_1240,local_1234,iVar5 + param_5,
                             param_6 - iVar5);
        if (local_1238 != (undefined1 *)0x0) {
          FUN_0056e1d0(local_1238);
        }
        goto joined_r0x0057a2bd;
      }
      iVar8 = FUN_00578f50(uVar9,uVar13,uVar15,uVar16,uVar17,CONCAT44(local_1230,local_1238),
                           local_122c,local_1218,local_1214,local_1240,local_1234,uVar18,
                           iVar5 + param_5,param_6 - iVar5,param_1);
      goto joined_r0x0057a2bd;
    }
    goto LAB_0057a4c2;
  }
  iVar8 = FUN_00573310(0x25,param_1,iVar5 + param_5,param_6 - iVar5);
  if ((iVar8 == 0) || ((uint)(param_6 - iVar5) < iVar8 + uVar7)) goto LAB_0057a00c;
  iVar5 = iVar5 + iVar8;
  iVar12 = iVar12 + 2;
  if ((uint)(param_6 - iVar5) <= uVar7) goto LAB_0057a00c;
switchD_00579ecf_caseD_f:
  iVar8 = local_1224[iVar12];
  goto joined_r0x00579c1a;
switchD_00579cfd_caseD_49:
  bVar14 = true;
  bVar3 = true;
  bVar4 = true;
  switch(iVar8) {
  case 0x49:
    if ((local_1224[iVar12 + 1] == 0x33) && (local_1224[iVar12 + 2] == 0x32)) {
      local_1248 = 5;
      iVar12 = iVar12 + 3;
    }
    else if ((local_1224[iVar12 + 1] == 0x36) && (local_1224[iVar12 + 2] == 0x34)) {
      local_1248 = 6;
      iVar12 = iVar12 + 3;
    }
    else {
      local_1248 = 4;
      iVar12 = iVar12 + 1;
    }
    break;
  case 0x68:
    local_1248 = 0;
    iVar12 = iVar12 + 1;
    break;
  case 0x6c:
    if (local_1224[iVar12 + 1] == 0x6c) {
      local_1248 = 2;
      iVar12 = iVar12 + 2;
    }
    else {
      local_1248 = 1;
      iVar12 = iVar12 + 1;
    }
    break;
  case 0x77:
    local_1248 = 3;
    iVar12 = iVar12 + 1;
  }
  goto switchD_00579e24_caseD_4a;
switchD_00579cfd_caseD_20:
  if (bVar14) goto switchD_00579cfd_caseD_21;
  switch(iVar8) {
  case 0x20:
    local_1214 = 1;
    break;
  case 0x23:
    local_1238 = (undefined1 *)0x1;
    break;
  case 0x2b:
    local_1218 = 1;
    break;
  case 0x2d:
    local_122c = 1;
  }
  goto switchD_00579d1b_caseD_21;
switchD_00579cfd_caseD_21:
  goto switchD_00579ecf_caseD_f;
}

