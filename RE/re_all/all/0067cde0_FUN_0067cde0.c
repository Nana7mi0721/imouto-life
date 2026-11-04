
uint FUN_0067cde0(int *param_1,int param_2)

{
  char cVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  bool bVar5;
  undefined1 uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  undefined4 *puVar11;
  
  if ((((param_1 == (int *)0x0) || (puVar2 = (undefined4 *)param_1[7], puVar2 == (undefined4 *)0x0))
      || (5 < param_2)) || (param_2 < 0)) {
    return 0xfffffffe;
  }
  if (((param_1[3] == 0) || ((*param_1 == 0 && (param_1[1] != 0)))) ||
     ((puVar2[1] == 0x29a && (param_2 != 4)))) {
    param_1[6] = (int)PTR_s_stream_error_00821ad8;
    return 0xfffffffe;
  }
  if (param_1[4] == 0) {
    param_1[6] = (int)PTR_s_buffer_error_00821ae4;
    return 0xfffffffb;
  }
  iVar8 = puVar2[10];
  *puVar2 = param_1;
  puVar2[10] = param_2;
  if (puVar2[1] == 0x2a) {
    if (puVar2[6] == 2) {
      iVar7 = FUN_0067c560(0,0,0);
      param_1[0xc] = iVar7;
      *(undefined1 *)(puVar2[2] + puVar2[5]) = 0x1f;
      iVar7 = puVar2[5];
      puVar2[5] = iVar7 + 1;
      *(undefined1 *)(puVar2[2] + iVar7 + 1) = 0x8b;
      iVar7 = puVar2[5];
      puVar2[5] = iVar7 + 1;
      *(undefined1 *)(puVar2[2] + iVar7 + 1) = 8;
      piVar3 = (int *)puVar2[7];
      iVar7 = puVar2[5] + 1;
      puVar2[5] = iVar7;
      if (piVar3 == (int *)0x0) {
        *(undefined1 *)(puVar2[2] + iVar7) = 0;
        iVar7 = puVar2[5];
        puVar2[5] = iVar7 + 1;
        *(undefined1 *)(puVar2[2] + iVar7 + 1) = 0;
        iVar7 = puVar2[5];
        puVar2[5] = iVar7 + 1;
        *(undefined1 *)(puVar2[2] + iVar7 + 1) = 0;
        iVar7 = puVar2[5];
        puVar2[5] = iVar7 + 1;
        *(undefined1 *)(puVar2[2] + iVar7 + 1) = 0;
        iVar7 = puVar2[5];
        puVar2[5] = iVar7 + 1;
        *(undefined1 *)(puVar2[2] + iVar7 + 1) = 0;
        iVar7 = puVar2[5];
        puVar2[5] = iVar7 + 1;
        if (puVar2[0x21] == 9) {
          uVar6 = 2;
        }
        else if (((int)puVar2[0x22] < 2) && (1 < (int)puVar2[0x21])) {
          uVar6 = 0;
        }
        else {
          uVar6 = 4;
        }
        *(undefined1 *)(puVar2[2] + iVar7 + 1) = uVar6;
        iVar7 = puVar2[5];
        puVar2[5] = iVar7 + 1;
        *(undefined1 *)(puVar2[2] + iVar7 + 1) = 0xb;
        puVar2[1] = 0x71;
        puVar2[5] = puVar2[5] + 1;
      }
      else {
        *(byte *)(puVar2[2] + iVar7) =
             (-(piVar3[9] != 0) & 0x10U) + (-(piVar3[0xb] != 0) & 2U) + (-(piVar3[7] != 0) & 8U) +
             (-(piVar3[4] != 0) & 4U) + (*piVar3 != 0);
        iVar7 = puVar2[5];
        puVar2[5] = iVar7 + 1;
        *(undefined1 *)(puVar2[2] + iVar7 + 1) = *(undefined1 *)(puVar2[7] + 4);
        iVar7 = puVar2[5];
        puVar2[5] = iVar7 + 1;
        *(char *)(puVar2[2] + iVar7 + 1) = (char)((uint)*(undefined4 *)(puVar2[7] + 4) >> 8);
        iVar7 = puVar2[5];
        puVar2[5] = iVar7 + 1;
        *(char *)(puVar2[2] + iVar7 + 1) = (char)((uint)*(undefined4 *)(puVar2[7] + 4) >> 0x10);
        iVar7 = puVar2[5];
        puVar2[5] = iVar7 + 1;
        *(char *)(puVar2[2] + iVar7 + 1) = (char)((uint)*(undefined4 *)(puVar2[7] + 4) >> 0x18);
        iVar7 = puVar2[5];
        puVar2[5] = iVar7 + 1;
        if (puVar2[0x21] == 9) {
          uVar6 = 2;
        }
        else if (((int)puVar2[0x22] < 2) && (1 < (int)puVar2[0x21])) {
          uVar6 = 0;
        }
        else {
          uVar6 = 4;
        }
        *(undefined1 *)(puVar2[2] + iVar7 + 1) = uVar6;
        iVar7 = puVar2[5];
        puVar2[5] = iVar7 + 1;
        *(undefined1 *)(puVar2[2] + iVar7 + 1) = *(undefined1 *)(puVar2[7] + 0xc);
        iVar7 = puVar2[5] + 1;
        puVar2[5] = iVar7;
        if (*(int *)(puVar2[7] + 0x10) != 0) {
          *(undefined1 *)(puVar2[2] + iVar7) = *(undefined1 *)(puVar2[7] + 0x14);
          iVar7 = puVar2[5];
          puVar2[5] = iVar7 + 1;
          *(char *)(puVar2[2] + iVar7 + 1) = (char)((uint)*(undefined4 *)(puVar2[7] + 0x14) >> 8);
          iVar7 = puVar2[5] + 1;
          puVar2[5] = iVar7;
        }
        if (*(int *)(puVar2[7] + 0x2c) != 0) {
          iVar7 = FUN_0067c560(param_1[0xc],puVar2[2],iVar7);
          param_1[0xc] = iVar7;
        }
        puVar2[8] = 0;
        puVar2[1] = 0x45;
      }
    }
    else {
      if (((int)puVar2[0x22] < 2) && (iVar7 = puVar2[0x21], 1 < iVar7)) {
        if (iVar7 < 6) {
          iVar7 = 1;
        }
        else {
          iVar7 = (iVar7 != 6) + 2;
        }
      }
      else {
        iVar7 = 0;
      }
      uVar10 = puVar2[0xc] * 0x1000 - 0x7800U | iVar7 << 6;
      if (puVar2[0x1b] != 0) {
        uVar10 = uVar10 | 0x20;
      }
      puVar2[1] = 0x71;
      FUN_0067d700(puVar2,(uVar10 - uVar10 % 0x1f) + 0x1f);
      if (puVar2[0x1b] != 0) {
        FUN_0067d700(puVar2,(uint)param_1[0xc] >> 0x10);
        FUN_0067d700(puVar2,param_1[0xc] & 0xffff);
      }
      iVar7 = FUN_0067c870(0,0,0);
      param_1[0xc] = iVar7;
    }
  }
  if (puVar2[1] == 0x45) {
    iVar7 = puVar2[7];
    if (*(int *)(iVar7 + 0x10) != 0) {
      uVar10 = puVar2[5];
      if ((uint)puVar2[8] < (*(uint *)(iVar7 + 0x14) & 0xffff)) {
        do {
          uVar9 = puVar2[5];
          if (uVar9 == puVar2[3]) {
            if ((*(int *)(iVar7 + 0x2c) != 0) && (uVar10 < uVar9)) {
              iVar7 = FUN_0067c560(param_1[0xc],puVar2[2] + uVar10,uVar9 - uVar10);
              param_1[0xc] = iVar7;
            }
            FUN_0067d730(param_1);
            uVar9 = puVar2[5];
            uVar10 = uVar9;
            if (uVar9 == puVar2[3]) break;
          }
          *(undefined1 *)(puVar2[2] + uVar9) =
               *(undefined1 *)(*(int *)(puVar2[7] + 0x10) + puVar2[8]);
          iVar4 = puVar2[8];
          puVar2[5] = puVar2[5] + 1;
          iVar7 = puVar2[7];
          puVar2[8] = iVar4 + 1U;
        } while (iVar4 + 1U < (*(uint *)(iVar7 + 0x14) & 0xffff));
      }
      if ((*(int *)(puVar2[7] + 0x2c) != 0) && (uVar10 < (uint)puVar2[5])) {
        iVar7 = FUN_0067c560(param_1[0xc],puVar2[2] + uVar10,puVar2[5] - uVar10);
        param_1[0xc] = iVar7;
      }
      if (puVar2[8] != *(int *)(puVar2[7] + 0x14)) goto LAB_0067d230;
      puVar2[8] = 0;
    }
    puVar2[1] = 0x49;
  }
LAB_0067d230:
  if (puVar2[1] == 0x49) {
    if (*(int *)(puVar2[7] + 0x1c) != 0) {
      uVar10 = puVar2[5];
      do {
        uVar9 = puVar2[5];
        if (uVar9 == puVar2[3]) {
          if ((*(int *)(puVar2[7] + 0x2c) != 0) && (uVar10 < uVar9)) {
            iVar7 = FUN_0067c560(param_1[0xc],puVar2[2] + uVar10,uVar9 - uVar10);
            param_1[0xc] = iVar7;
          }
          FUN_0067d730(param_1);
          uVar9 = puVar2[5];
          uVar10 = uVar9;
          if (uVar9 == puVar2[3]) {
            bVar5 = true;
            break;
          }
        }
        cVar1 = *(char *)(*(int *)(puVar2[7] + 0x1c) + -1 + puVar2[8] + 1);
        puVar2[8] = puVar2[8] + 1;
        *(char *)(puVar2[2] + uVar9) = cVar1;
        puVar2[5] = puVar2[5] + 1;
        bVar5 = false;
        uVar9 = uVar10;
      } while (cVar1 != '\0');
      if ((*(int *)(puVar2[7] + 0x2c) != 0) && (uVar9 < (uint)puVar2[5])) {
        iVar7 = FUN_0067c560(param_1[0xc],puVar2[2] + uVar9,puVar2[5] - uVar9);
        param_1[0xc] = iVar7;
      }
      if (bVar5) goto LAB_0067d2f2;
      puVar2[8] = 0;
    }
    puVar2[1] = 0x5b;
  }
LAB_0067d2f2:
  if (puVar2[1] == 0x5b) {
    if (*(int *)(puVar2[7] + 0x24) != 0) {
      uVar10 = puVar2[5];
      do {
        uVar9 = puVar2[5];
        if (uVar9 == puVar2[3]) {
          if ((*(int *)(puVar2[7] + 0x2c) != 0) && (uVar10 < uVar9)) {
            iVar7 = FUN_0067c560(param_1[0xc],puVar2[2] + uVar10,uVar9 - uVar10);
            param_1[0xc] = iVar7;
          }
          FUN_0067d730(param_1);
          uVar9 = puVar2[5];
          uVar10 = uVar9;
          if (uVar9 == puVar2[3]) {
            bVar5 = true;
            break;
          }
        }
        cVar1 = *(char *)(*(int *)(puVar2[7] + 0x24) + -1 + puVar2[8] + 1);
        puVar2[8] = puVar2[8] + 1;
        *(char *)(puVar2[2] + uVar9) = cVar1;
        puVar2[5] = puVar2[5] + 1;
        bVar5 = false;
        uVar9 = uVar10;
      } while (cVar1 != '\0');
      if ((*(int *)(puVar2[7] + 0x2c) != 0) && (uVar9 < (uint)puVar2[5])) {
        iVar7 = FUN_0067c560(param_1[0xc],puVar2[2] + uVar9,puVar2[5] - uVar9);
        param_1[0xc] = iVar7;
      }
      if (bVar5) goto LAB_0067d3b1;
    }
    puVar2[1] = 0x67;
  }
LAB_0067d3b1:
  if (puVar2[1] == 0x67) {
    if (*(int *)(puVar2[7] + 0x2c) != 0) {
      if ((uint)puVar2[3] < puVar2[5] + 2) {
        FUN_0067d730(param_1);
      }
      if ((uint)puVar2[3] < puVar2[5] + 2) goto LAB_0067d421;
      *(char *)(puVar2[2] + puVar2[5]) = (char)param_1[0xc];
      iVar7 = puVar2[5];
      puVar2[5] = iVar7 + 1;
      *(char *)(puVar2[2] + iVar7 + 1) = (char)((uint)param_1[0xc] >> 8);
      puVar2[5] = puVar2[5] + 1;
      iVar7 = FUN_0067c560(0,0,0);
      param_1[0xc] = iVar7;
    }
    puVar2[1] = 0x71;
  }
LAB_0067d421:
  if (puVar2[5] == 0) {
    if (((param_1[1] == 0) &&
        ((int)(param_2 * 2 - ((param_2 < 5) - 1 & 9)) <= (int)(iVar8 * 2 - ((iVar8 < 5) - 1 & 9))))
       && (param_2 != 4)) {
      param_1[6] = (int)PTR_s_buffer_error_00821ae4;
      return 0xfffffffb;
    }
  }
  else {
    FUN_0067d730(param_1);
    if (param_1[4] == 0) {
      puVar2[10] = 0xffffffff;
      return 0;
    }
  }
  if (puVar2[1] == 0x29a) {
    if (param_1[1] != 0) {
      param_1[6] = (int)PTR_s_buffer_error_00821ae4;
      return 0xfffffffb;
    }
LAB_0067d4bf:
    if ((puVar2[0x1d] == 0) && ((param_2 == 0 || (puVar2[1] == 0x29a)))) goto LAB_0067d5c7;
  }
  else if (param_1[1] == 0) goto LAB_0067d4bf;
  if (puVar2[0x22] == 2) {
    iVar8 = FUN_0067e970(puVar2,param_2);
  }
  else if (puVar2[0x22] == 3) {
    iVar8 = FUN_0067e680(puVar2,param_2);
  }
  else {
    iVar8 = (**(code **)(&DAT_00821a50 + puVar2[0x21] * 0xc))(puVar2,param_2);
  }
  if ((iVar8 == 2) || (iVar8 == 3)) {
    puVar2[1] = 0x29a;
  }
  if ((iVar8 == 0) || (iVar8 == 2)) {
    if (param_1[4] == 0) {
      puVar2[10] = 0xffffffff;
    }
    return 0;
  }
  if (iVar8 == 1) {
    if (param_2 == 1) {
      FUN_0067f5e0(puVar2);
    }
    else if ((param_2 != 5) && (FUN_0067f530(puVar2,0,0,0), param_2 == 3)) {
      *(undefined2 *)(puVar2[0x11] + -2 + puVar2[0x13] * 2) = 0;
      uVar10 = puVar2[0x13] * 2 - 2;
      puVar11 = (undefined4 *)puVar2[0x11];
      for (uVar9 = uVar10 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
        *puVar11 = 0;
        puVar11 = puVar11 + 1;
      }
      for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
        *(undefined1 *)puVar11 = 0;
        puVar11 = (undefined4 *)((int)puVar11 + 1);
      }
      if (puVar2[0x1d] == 0) {
        puVar2[0x1b] = 0;
        puVar2[0x17] = 0;
        puVar2[0x5ad] = 0;
      }
    }
    FUN_0067d730(param_1);
    if (param_1[4] == 0) {
      puVar2[10] = 0xffffffff;
      return 0;
    }
  }
LAB_0067d5c7:
  if (param_2 != 4) {
    return 0;
  }
  if ((int)puVar2[6] < 1) {
    return 1;
  }
  if (puVar2[6] == 2) {
    *(char *)(puVar2[2] + puVar2[5]) = (char)param_1[0xc];
    iVar8 = puVar2[5];
    puVar2[5] = iVar8 + 1;
    *(char *)(puVar2[2] + iVar8 + 1) = (char)((uint)param_1[0xc] >> 8);
    iVar8 = puVar2[5];
    puVar2[5] = iVar8 + 1;
    *(char *)(puVar2[2] + iVar8 + 1) = (char)((uint)param_1[0xc] >> 0x10);
    iVar8 = puVar2[5];
    puVar2[5] = iVar8 + 1;
    *(char *)(puVar2[2] + iVar8 + 1) = (char)((uint)param_1[0xc] >> 0x18);
    iVar8 = puVar2[5];
    puVar2[5] = iVar8 + 1;
    *(char *)(puVar2[2] + iVar8 + 1) = (char)param_1[2];
    iVar8 = puVar2[5];
    puVar2[5] = iVar8 + 1;
    *(char *)(puVar2[2] + iVar8 + 1) = (char)((uint)param_1[2] >> 8);
    iVar8 = puVar2[5];
    puVar2[5] = iVar8 + 1;
    *(char *)(puVar2[2] + iVar8 + 1) = (char)((uint)param_1[2] >> 0x10);
    iVar8 = puVar2[5];
    puVar2[5] = iVar8 + 1;
    *(char *)(puVar2[2] + iVar8 + 1) = (char)((uint)param_1[2] >> 0x18);
    puVar2[5] = puVar2[5] + 1;
  }
  else {
    FUN_0067d700(puVar2,(uint)param_1[0xc] >> 0x10);
    FUN_0067d700(puVar2,param_1[0xc] & 0xffff);
  }
  FUN_0067d730(param_1);
  if (0 < (int)puVar2[6]) {
    puVar2[6] = -puVar2[6];
  }
  return (uint)(puVar2[5] == 0);
}

