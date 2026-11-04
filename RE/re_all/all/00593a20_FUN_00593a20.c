
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00593a20(int param_1,uint param_2,uint param_3,uint param_4,int param_5,uint param_6,
                int param_7,int param_8,int param_9,int param_10,int param_11,int param_12,
                undefined4 param_13,int param_14,int param_15,int *param_16)

{
  int *piVar1;
  float fVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 uVar8;
  float local_1274;
  undefined4 local_1270;
  int local_126c;
  int local_1268;
  int local_1264;
  uint local_1260;
  int local_125c;
  int local_1258;
  int local_1254;
  int *local_1250;
  float local_124c;
  int *local_1248;
  uint local_1244;
  undefined4 local_1240;
  int *local_123c;
  int local_1238;
  float local_1234;
  int local_1230;
  float local_122c;
  int local_1228;
  undefined4 local_1224;
  undefined4 local_1220;
  undefined4 local_121c;
  undefined4 local_1218;
  int local_1214;
  int local_1210;
  int local_120c;
  float local_1208;
  float local_1204;
  float local_1200;
  float local_11fc;
  float local_11f8;
  float local_11f4;
  float local_11f0;
  float local_11ec;
  float local_11e8;
  float local_11e4;
  float local_11e0;
  undefined4 local_11dc;
  undefined4 local_11d8;
  undefined4 local_11d4;
  undefined4 local_11d0;
  undefined4 local_11cc;
  undefined4 local_11c8;
  undefined4 local_11c4;
  undefined4 local_11c0;
  int local_11bc;
  int local_11b8;
  int local_11b4;
  int local_11b0;
  int local_11ac;
  int local_11a8;
  int local_11a4;
  int local_11a0;
  int local_119c;
  undefined1 local_1198 [16];
  undefined1 local_1188 [16];
  undefined1 local_1178 [16];
  int local_1168;
  uint local_1164;
  uint local_1160;
  uint local_115c;
  uint local_1158;
  int local_1154;
  float local_1150;
  int local_114c;
  int local_1148;
  int local_1144;
  int local_1140;
  int local_113c;
  int local_1138;
  int local_1134;
  int local_1130;
  undefined4 local_112c;
  int local_1128;
  int local_1124;
  int local_1120;
  int *local_450;
  int *local_44c;
  int *local_448;
  float local_444;
  undefined1 local_440 [1084];
  undefined4 uStack_4;
  
  uStack_4 = 0x593a2a;
  local_123c = (int *)0x0;
  local_1250 = (int *)0x0;
  local_1248 = (int *)0x0;
  local_124c = 0.0;
  local_1260 = 0xffffffff;
  local_1240 = 0xffffffff;
  local_1258 = 0;
  local_125c = 0;
  local_1254 = 0;
  local_1270 = 0;
  if ((((DAT_00cc47d0 == 0) || ((int)param_2 < 0)) || ((param_2 & 0x7c000000) != DAT_00cc47f8)) ||
     (((DAT_00cc4800 <= (int)(param_2 & 0xffff) ||
       (local_123c = *(int **)(DAT_00cc47d4 + (param_2 & 0xffff) * 4), local_123c == (int *)0x0)) ||
      ((*local_123c * 0x10000 != (param_2 & 0x3ff0000) || (local_123c[4] != 0)))))) {
    if (DAT_00cc79c0 == 0) {
      return -1;
    }
    if ((int)param_2 < 0) {
      return -1;
    }
    if ((param_2 & 0x7c000000) != DAT_00cc79e8) {
      return -1;
    }
    if (DAT_00cc79f0 <= (int)(param_2 & 0xffff)) {
      return -1;
    }
    piVar1 = *(int **)(DAT_00cc79c4 + (param_2 & 0xffff) * 4);
    if (piVar1 == (int *)0x0) {
      return -1;
    }
    if (*piVar1 * 0x10000 != (param_2 & 0x3ff0000)) {
      return -1;
    }
    if (piVar1[4] != 0) {
      return -1;
    }
    local_1264 = piVar1[0x48];
    local_1268 = piVar1[0x49];
  }
  else {
    local_1264 = local_123c[0x18];
    local_1268 = local_123c[0x19];
  }
  if ((((DAT_00cc47d0 == 0) || ((int)param_4 < 0)) ||
      (((param_4 & 0x7c000000) != DAT_00cc47f8 ||
       (((DAT_00cc4800 <= (int)(param_4 & 0xffff) ||
         (local_1250 = *(int **)(DAT_00cc47d4 + (param_4 & 0xffff) * 4), local_1250 == (int *)0x0))
        || (*local_1250 * 0x10000 != (param_4 & 0x3ff0000))))))) || (local_1250[4] != 0)) {
    if (DAT_00cc79c0 == 0) {
      return -1;
    }
    if ((int)param_4 < 0) {
      return -1;
    }
    if ((param_4 & 0x7c000000) != DAT_00cc79e8) {
      return -1;
    }
    if (DAT_00cc79f0 <= (int)(param_4 & 0xffff)) {
      return -1;
    }
    piVar1 = *(int **)(DAT_00cc79c4 + (param_4 & 0xffff) * 4);
    if (piVar1 == (int *)0x0) {
      return -1;
    }
    if (*piVar1 * 0x10000 != (param_4 & 0x3ff0000)) {
      return -1;
    }
    if (piVar1[4] != 0) {
      return -1;
    }
    iVar5 = piVar1[0x48];
    local_126c = piVar1[0x49];
  }
  else {
    iVar5 = local_1250[0x18];
    local_126c = local_1250[0x19];
  }
  iVar3 = FUN_005176a0(DAT_00a38120);
  if (((iVar3 != 0) && (DAT_00cc47d0 != 0)) &&
     ((-1 < (int)DAT_00a38120 &&
      (((DAT_00a38120 & 0x7c000000) == DAT_00cc47f8 && ((int)(DAT_00a38120 & 0xffff) < DAT_00cc4800)
       ))))) {
    local_124c = *(float *)(DAT_00cc47d4 + (DAT_00a38120 & 0xffff) * 4);
  }
  if (param_9 <= param_7) {
    return -1;
  }
  if (param_10 <= param_8) {
    return -1;
  }
  if (param_1 == 0) {
    if (0x18 < param_6) {
      return -1;
    }
  }
  else {
    if (DAT_00cc47d0 == 0) {
      return -1;
    }
    if ((int)param_3 < 0) {
      return -1;
    }
    if ((param_3 & 0x7c000000) != DAT_00cc47f8) {
      return -1;
    }
    if (DAT_00cc4800 <= (int)(param_3 & 0xffff)) {
      return -1;
    }
    local_1248 = *(int **)(DAT_00cc47d4 + (param_3 & 0xffff) * 4);
    if (local_1248 == (int *)0x0) {
      return -1;
    }
    if (*local_1248 * 0x10000 != (param_3 & 0x3ff0000)) {
      return -1;
    }
    if (local_1248[4] != 0) {
      return -1;
    }
    if ((int)param_6 < 0) {
      return -1;
    }
    if (0x21 < (int)param_6) {
      return -1;
    }
  }
  if (param_5 < 0) {
    param_5 = 0;
  }
  else if (0xff < param_5) {
    param_5 = 0xff;
  }
  local_1274 = (float)param_5 / (float)_DAT_0081ec30;
  if (param_7 < 0) {
    param_14 = param_14 - param_7;
    param_11 = param_11 - param_7;
    param_7 = 0;
  }
  if (param_8 < 0) {
    param_12 = param_12 - param_8;
    param_15 = param_15 - param_8;
    param_8 = 0;
  }
  if (param_14 < 0) {
    param_7 = param_7 - param_14;
    param_11 = param_11 - param_14;
    param_14 = 0;
  }
  if (param_15 < 0) {
    param_12 = param_12 - param_15;
    param_8 = param_8 - param_15;
    param_15 = 0;
  }
  if (param_9 <= param_7) {
    return 0;
  }
  if (param_10 <= param_8) {
    return 0;
  }
  if (local_1264 < param_9) {
    param_9 = local_1264;
  }
  if (local_1268 < param_10) {
    param_10 = local_1268;
  }
  if (local_1264 <= param_7) {
    return 0;
  }
  if (local_1268 <= param_8) {
    return 0;
  }
  if (param_9 < 1) {
    return 0;
  }
  if (param_10 < 1) {
    return 0;
  }
  if (iVar5 <= param_14) {
    return 0;
  }
  if (local_126c <= param_15) {
    return 0;
  }
  iVar3 = param_9 - param_7;
  local_1268 = param_10 - param_8;
  if (iVar3 < 1) {
    return 0;
  }
  if (local_1268 < 1) {
    return 0;
  }
  local_1264 = iVar3;
  FUN_0056d380(&local_1238,0,0xa0);
  local_1154 = 0;
  local_1138 = 1;
  if ((param_1 == 0) && (iVar7 = 2, param_6 == 2)) {
    iVar3 = *param_16;
    param_16 = param_16 + 1;
    if (2 < iVar3) {
      iVar7 = (uint)(4 < iVar3) * 4 + 4;
    }
    if (iVar5 < local_1264 / iVar7 + param_14) {
      local_1264 = (iVar5 - param_14) * iVar7;
      param_9 = local_1264 + param_7;
    }
    local_1138 = iVar7;
    if (local_126c < local_1268 / iVar7 + param_15) {
      local_1268 = (local_126c - param_15) * iVar7;
      goto LAB_00593f3d;
    }
  }
  else {
    if (iVar5 < iVar3 + param_14) {
      local_1264 = iVar5 - param_14;
      param_9 = local_1264 + param_7;
    }
    if (local_126c < local_1268 + param_15) {
      local_1268 = local_126c - param_15;
LAB_00593f3d:
      param_10 = local_1268 + param_8;
    }
  }
  if ((local_1264 < 1) || (local_1268 < 1)) {
    return 0;
  }
  local_1150 = local_1274;
  local_115c = param_3;
  local_1148 = param_7;
  local_1144 = param_8;
  local_1140 = param_9;
  local_113c = param_10;
  local_1134 = param_11;
  local_1130 = param_12;
  local_112c = param_13;
  local_450 = local_123c;
  local_44c = local_1250;
  local_1168 = param_1;
  local_1164 = param_6;
  local_448 = local_1248;
  local_444 = local_124c;
  uVar8 = local_1270;
  local_1128 = param_14;
  local_1124 = param_15;
  if (param_1 != 0) {
    switch(param_6) {
    case 1:
      break;
    default:
      goto switchD_0059404f_caseD_2;
    case 0x11:
    case 0x13:
    case 0x14:
    case 0x15:
    case 0x16:
    case 0x17:
    case 0x18:
    case 0x19:
    case 0x1a:
    case 0x1b:
    case 0x1c:
    case 0x1d:
    case 0x1e:
    case 0x1f:
    case 0x20:
    case 0x21:
      goto switchD_0059404f_caseD_11;
    case 0x12:
      uVar8 = 1;
    }
    local_11a8 = *param_16;
    local_11a4 = param_16[1];
    local_11a0 = param_16[2];
    local_119c = param_16[3];
    goto LAB_005944df;
  }
  switch(param_6) {
  case 0:
    local_11fc = ((float)*param_16 * (float)_DAT_00829840) / (float)_DAT_0081ec30;
    local_11f8 = ((float)_DAT_00829840 * (float)param_16[1]) / (float)_DAT_0081ec30;
    break;
  case 1:
    local_1238 = *param_16;
    local_1234 = (float)param_16[1] / (float)_DAT_00829840;
    break;
  case 2:
    local_1154 = 1;
    break;
  case 3:
    goto LAB_00594108;
  case 4:
    goto LAB_005941d3;
  case 5:
    goto LAB_005941f3;
  case 7:
    goto LAB_00594249;
  case 8:
    goto LAB_0059429b;
  case 9:
    goto LAB_00594402;
  case 0xc:
  case 0xe:
    local_11b4 = -1;
    break;
  case 0xd:
  case 0xf:
    local_11b4 = *param_16;
    FUN_00515880(param_2,&local_1274,&local_1248);
    FUN_00515880(local_11b4,&local_124c,&local_1250);
    if (((local_1274 != local_124c) && ((float)((int)local_1274 / 2) != local_124c)) &&
       ((float)((int)((int)local_1274 + ((int)local_1274 >> 0x1f & 3U)) >> 2) != local_124c)) {
      return -1;
    }
    if (((local_1248 != local_1250) && ((int *)((int)local_1248 / 2) != local_1250)) &&
       ((int *)((int)((int)local_1248 + ((int)local_1248 >> 0x1f & 3U)) >> 2) != local_1250)) {
      return -1;
    }
    break;
  case 0x10:
  case 0x11:
    local_11b0 = *param_16;
    local_11ac = param_16[1];
    break;
  case 0x12:
    uVar8 = 1;
LAB_00594108:
    local_1230 = *param_16;
    local_122c = (float)param_16[1];
    local_1228 = param_16[2];
    if (local_1228 != 0) {
      FUN_00544000(param_16[3],&local_1258,&local_125c,&local_1254);
      local_126c = param_16[4];
      fVar2 = (float)_DAT_0081ec30;
      local_1274 = (float)local_1258 / fVar2;
      puVar4 = (undefined4 *)
               FUN_00543f20(local_1198,local_1274,(float)local_125c / fVar2,
                            (float)local_1254 / fVar2,(float)local_126c / fVar2);
      local_1224 = *puVar4;
      local_1220 = puVar4[1];
      local_121c = puVar4[2];
      local_1218 = puVar4[3];
    }
    goto LAB_005944df;
  case 0x13:
    uVar8 = 1;
LAB_005941d3:
    local_1214 = *param_16;
    local_1210 = param_16[1];
    goto LAB_005944df;
  case 0x14:
    uVar8 = 1;
LAB_005941f3:
    local_120c = *param_16;
    local_1208 = (float)param_16[1];
    local_1204 = ((float)param_16[2] * (float)_DAT_00829840) / (float)_DAT_0081ec30;
    local_1200 = ((float)_DAT_00829840 * (float)param_16[3]) / (float)_DAT_0081ec30;
    goto LAB_005944df;
  case 0x15:
switchD_0059404f_caseD_11:
    uVar8 = 1;
    goto LAB_005944df;
  case 0x16:
    uVar8 = 1;
LAB_00594249:
    local_11f4 = (float)*param_16;
    local_11f0 = (float)param_16[1];
    local_11ec = (float)param_16[2] / (float)_DAT_00829840;
    local_11e8 = (float)param_16[3];
    local_11e4 = (float)param_16[4];
    goto LAB_005944df;
  case 0x17:
    uVar8 = 1;
LAB_0059429b:
    local_11e0 = (float)*param_16;
    FUN_00544000(param_16[1],&local_1258,&local_125c,&local_1254);
    local_126c = param_16[2];
    fVar2 = (float)_DAT_0081ec30;
    local_1274 = (float)local_1258 / fVar2;
    puVar4 = (undefined4 *)
             FUN_00543f20(local_1188,local_1274,(float)local_125c / fVar2,(float)local_1254 / fVar2,
                          (float)local_126c / fVar2);
    local_11dc = *puVar4;
    local_11d8 = puVar4[1];
    local_11d4 = puVar4[2];
    local_11d0 = puVar4[3];
    FUN_00544000(param_16[3],&local_1258,&local_125c,&local_1254);
    local_126c = param_16[4];
    fVar2 = (float)_DAT_0081ec30;
    local_1274 = (float)local_1258 / fVar2;
    puVar4 = (undefined4 *)
             FUN_00543f20(local_1178,local_1274,(float)local_125c / fVar2,(float)local_1254 / fVar2,
                          (float)local_126c / fVar2);
    local_11cc = *puVar4;
    local_11c8 = puVar4[1];
    local_11c4 = puVar4[2];
    local_11c0 = puVar4[3];
    goto LAB_005944df;
  case 0x18:
    uVar8 = 1;
LAB_00594402:
    local_11bc = *param_16;
    local_11b8 = param_16[1];
    goto LAB_005944df;
  }
switchD_0059404f_caseD_2:
  uVar8 = local_1270;
LAB_005944df:
  FUN_005dbb30(&local_1168,&local_1238);
  local_1244 = param_2;
  local_114c = 0;
  uVar6 = local_1240;
  if (0 < local_1120) {
    do {
      local_1160 = param_2;
      local_1158 = param_4;
      iVar5 = FUN_005dbbb0(&local_1168,&local_1244,&local_1260);
      if ((iVar5 < 0) ||
         ((((DAT_00cc47d0 == 0 || ((int)local_1260 < 0)) ||
           (((local_1260 & 0x7c000000) != DAT_00cc47f8 ||
            ((((DAT_00cc4800 <= (int)(local_1260 & 0xffff) ||
               (piVar1 = *(int **)(DAT_00cc47d4 + (local_1260 & 0xffff) * 4), piVar1 == (int *)0x0))
              || (*piVar1 * 0x10000 != (local_1260 & 0x3ff0000))) || (piVar1[4] != 0)))))) &&
          (((DAT_00cc79c0 == 0 || ((int)local_1260 < 0)) ||
           (((local_1260 & 0x7c000000) != DAT_00cc79e8 ||
            (((DAT_00cc79f0 <= (int)(local_1260 & 0xffff) ||
              (piVar1 = *(int **)(DAT_00cc79c4 + (local_1260 & 0xffff) * 4), piVar1 == (int *)0x0))
             || ((*piVar1 * 0x10000 != (local_1260 & 0x3ff0000) || (piVar1[4] != 0))))))))))))
      break;
      local_1160 = local_1244;
      local_1158 = local_1260;
      if (param_1 == 0) {
        switch(param_6) {
        case 0:
          uVar6 = FUN_00586bb0(&local_1168,local_11fc,local_11f8);
          break;
        case 1:
          uVar6 = FUN_00586e60(&local_1168,local_1238,local_1234);
          break;
        case 2:
          uVar6 = FUN_0058b920(&local_1168,local_1138);
          break;
        case 3:
        case 0x12:
          uVar6 = FUN_0058c750(&local_1168,local_1230,local_122c,local_1228,&local_1224,uVar8);
          break;
        case 4:
        case 0x13:
          uVar6 = FUN_0058ce60(&local_1168,local_1214,local_1210,uVar8);
          break;
        case 5:
        case 0x14:
          uVar6 = FUN_0058d210(&local_1168,local_120c,local_1208,local_1204,local_1200,uVar8);
          break;
        case 6:
        case 0x15:
          uVar6 = FUN_0058daa0(&local_1168,uVar8);
          break;
        case 7:
        case 0x16:
          uVar6 = FUN_0058dc30(&local_1168,local_11f4,local_11f0,local_11ec,local_11e8,local_11e4,
                               uVar8);
          break;
        case 8:
        case 0x17:
          uVar6 = FUN_0058e4a0(&local_1168,local_11e0,&local_11dc,&local_11cc,uVar8);
          break;
        case 9:
        case 0x18:
          uVar6 = FUN_0058e970(&local_1168,local_11bc,local_11b8,uVar8);
          break;
        case 10:
          uVar6 = FUN_0058ed00(&local_1168);
          break;
        case 0xb:
          uVar6 = FUN_0058edf0(&local_1168);
          break;
        case 0xc:
        case 0xd:
        case 0xe:
        case 0xf:
          uVar6 = FUN_0058ef30(&local_1168,local_11b4);
          break;
        case 0x10:
          uVar6 = FUN_00590800(&local_1168,local_11b0,local_11ac);
          break;
        case 0x11:
          uVar6 = FUN_00590830(&local_1168,local_11b0,local_11ac);
        }
      }
      else {
        switch(param_6) {
        case 0:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 0xb:
        case 0xc:
        case 0xd:
        case 0xe:
        case 0xf:
        case 0x10:
        case 0x11:
        case 0x13:
        case 0x14:
        case 0x15:
        case 0x16:
        case 0x17:
        case 0x18:
        case 0x19:
        case 0x1a:
        case 0x1b:
        case 0x1c:
        case 0x1d:
        case 0x1e:
        case 0x1f:
        case 0x20:
        case 0x21:
          uVar6 = FUN_00590860(&local_1168,uVar8);
          break;
        case 1:
        case 0x12:
          uVar6 = FUN_005937e0(&local_1168,local_11a8,local_11a4,local_11a0,local_119c,uVar8);
        }
      }
      if ((((local_1154 != 0) && (param_2 == param_4)) && (local_114c == 0)) &&
         (iVar5 = FUN_00546c90(local_1264,local_1268,local_440), iVar5 == 0)) {
        FUN_005492e0(local_440,0,0,0,0);
        FUN_00525f80(0,0,0,0,local_440,0,param_7,param_8,param_2);
        FUN_005421c0(local_440);
      }
      local_1244 = local_1260;
      local_114c = local_114c + 1;
    } while (local_114c < local_1120);
  }
  FUN_005dbb90();
  local_1160 = param_2;
  local_1158 = param_4;
  FUN_005dbbe0(&local_1168,local_1260,uVar6);
  return -(uint)(local_114c != local_1120);
}

