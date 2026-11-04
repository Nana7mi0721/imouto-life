
undefined4 FUN_0055ca10(undefined4 param_1,int *param_2,int *param_3)

{
  char cVar1;
  bool bVar2;
  short sVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  short *psVar7;
  ushort *puVar8;
  ushort *puVar9;
  char *pcVar10;
  undefined4 uVar11;
  undefined4 local_20c;
  int local_208;
  char *local_204;
  short local_200;
  short local_1fe [255];
  
  local_20c = 0xffffffff;
  local_200 = 0;
  _memset(local_1fe,0,0x1fe);
  iVar5 = FUN_0055ba80(param_1,&local_204,&local_208,0);
  if (iVar5 < 0) {
    return 0xffffffff;
  }
  if (local_208 < 3) goto LAB_0055cdbc;
  if (local_208 < 1) {
LAB_0055cb3c:
    if (DAT_00aba250 == 0) {
      FUN_0057a980();
    }
    uVar11 = 0x3a4;
    pcVar10 = local_204;
  }
  else {
    cVar1 = *local_204;
    if (((cVar1 == -1) && (1 < local_208)) && (local_204[1] == -2)) {
      if (DAT_00aba250 == 0) {
        FUN_0057a980();
      }
      uVar11 = 0x4b0;
      pcVar10 = local_204 + 2;
    }
    else if (((cVar1 == -2) && (1 < local_208)) && (local_204[1] == -1)) {
      if (DAT_00aba250 == 0) {
        FUN_0057a980();
      }
      uVar11 = 0x4b1;
      pcVar10 = local_204 + 2;
    }
    else {
      if (((cVar1 != -0x11) || (local_208 < 2)) ||
         ((local_204[1] != -0x45 || ((local_208 < 3 || (local_204[2] != -0x41))))))
      goto LAB_0055cb3c;
      if (DAT_00aba250 == 0) {
        FUN_0057a980();
      }
      uVar11 = 0xfde9;
      pcVar10 = local_204 + 3;
    }
  }
  FUN_005764b0(pcVar10,0xffffffff,uVar11,&local_200,0x1e0,DAT_00aba250);
  psVar7 = &local_200;
  if (local_200 != 0) {
    sVar3 = local_200;
    do {
      if (sVar3 == 0x4c) break;
      sVar3 = psVar7[1];
      psVar7 = psVar7 + 1;
    } while (sVar3 != 0);
  }
  if (DAT_00aba250 == 0) {
    FUN_0057a980();
  }
  iVar5 = FUN_00577640(DAT_00aba250,psVar7,L"LOOPSTART",9);
  if (iVar5 == 0) {
    puVar8 = (ushort *)(psVar7 + 9);
    uVar4 = psVar7[9];
    while (uVar4 != 0) {
      if (uVar4 == 0x3d) {
        uVar4 = *puVar8;
        if (uVar4 != 0) goto LAB_0055cbf3;
        break;
      }
      puVar9 = puVar8 + 1;
      puVar8 = puVar8 + 1;
      uVar4 = *puVar9;
    }
  }
LAB_0055cdbc:
  FUN_0056e1d0(local_204);
  return local_20c;
LAB_0055cbf3:
  if ((uVar4 < 0x30) || (0x39 < uVar4)) {
    uVar4 = puVar8[1];
    puVar8 = puVar8 + 1;
    if (uVar4 == 0) goto LAB_0055cdbc;
    goto LAB_0055cbf3;
  }
  if (*puVar8 == 0) goto LAB_0055cdbc;
  uVar4 = *puVar8;
  puVar9 = puVar8;
  while ((0x2f < uVar4 && (*puVar9 < 0x3a))) {
    puVar9 = puVar9 + 1;
    uVar4 = *puVar9;
  }
  if (*puVar9 == 0) goto LAB_0055cdbc;
  *puVar9 = 0;
  if (DAT_00aba250 == 0) {
    FUN_0057a980();
  }
  iVar5 = FUN_0057a7b0(DAT_00aba250,puVar8);
  puVar9 = puVar9 + 1;
  uVar4 = *puVar9;
  while ((uVar4 != 0 && (uVar4 != 0x4c))) {
    puVar8 = puVar9 + 1;
    puVar9 = puVar9 + 1;
    uVar4 = *puVar8;
  }
  if (DAT_00aba250 == 0) {
    FUN_0057a980();
  }
  iVar6 = FUN_00577640(DAT_00aba250,puVar9,L"LOOPEND",7);
  if (iVar6 == 0) {
    bVar2 = false;
    puVar9 = puVar9 + 7;
  }
  else {
    if (DAT_00aba250 == 0) {
      FUN_0057a980();
    }
    iVar6 = FUN_00577640(DAT_00aba250,puVar9,L"LOOPLENGTH",10);
    if (iVar6 != 0) goto LAB_0055cdbc;
    bVar2 = true;
    puVar9 = puVar9 + 10;
  }
  uVar4 = *puVar9;
  while (uVar4 != 0) {
    if (uVar4 == 0x3d) {
      uVar4 = *puVar9;
      goto joined_r0x0055cd0d;
    }
    puVar8 = puVar9 + 1;
    puVar9 = puVar9 + 1;
    uVar4 = *puVar8;
  }
  goto LAB_0055cdbc;
joined_r0x0055cd0d:
  if (uVar4 == 0) goto LAB_0055cdbc;
  if ((0x2f < uVar4) && (uVar4 < 0x3a)) {
    if (*puVar9 != 0) {
      uVar4 = *puVar9;
      puVar8 = puVar9;
      while ((0x2f < uVar4 && (*puVar8 < 0x3a))) {
        puVar8 = puVar8 + 1;
        uVar4 = *puVar8;
      }
      *puVar8 = 0;
      if (bVar2) {
        if (DAT_00aba250 == 0) {
          FUN_0057a980();
        }
        iVar6 = FUN_0057a7b0(DAT_00aba250,puVar9);
        iVar6 = iVar6 + iVar5;
      }
      else {
        if (DAT_00aba250 == 0) {
          FUN_0057a980();
        }
        iVar6 = FUN_0057a7b0(DAT_00aba250,puVar9);
      }
      if (iVar5 < iVar6) {
        if (param_2 != (int *)0x0) {
          *param_2 = iVar5;
        }
        if (param_3 != (int *)0x0) {
          *param_3 = iVar6;
        }
        local_20c = 0;
      }
    }
    goto LAB_0055cdbc;
  }
  uVar4 = puVar9[1];
  puVar9 = puVar9 + 1;
  goto joined_r0x0055cd0d;
}

