
undefined4 FUN_005960c0(int param_1,undefined4 param_2,DWORD param_3,undefined4 param_4)

{
  uint uVar1;
  ushort *puVar2;
  uint uVar3;
  DWORD DVar4;
  undefined4 uVar5;
  byte bVar6;
  UINT UVar7;
  uint uVar8;
  LPVOID pvBuffer;
  int iVar9;
  uint local_6c;
  undefined4 local_68;
  tagSIZE local_60;
  MAT2 local_58;
  WCHAR local_48 [8];
  _GLYPHMETRICS local_38;
  tagGCP_RESULTSW local_24;
  
  uVar1 = param_3;
  local_68 = 0;
  local_6c = 0;
  if (param_3 == 0x20) {
    bVar6 = 1;
  }
  else {
    bVar6 = (param_3 != DAT_00a4ba9c) - 1U & 2;
    if (((bVar6 == 0) && (0 < *(int *)(param_1 + 0x92d9c))) &&
       (iVar9 = *(int *)(*(int *)(param_1 + 0x30) + 0x14), iVar9 != 0)) {
      uVar3 = *(uint *)(iVar9 + 0xc);
      uVar8 = 0;
      puVar2 = (ushort *)(iVar9 + 0x10);
      if (uVar3 != 0) {
        do {
          if ((*puVar2 <= param_3) && (param_3 < (uint)puVar2[1] + (uint)*puVar2)) break;
          uVar8 = uVar8 + 1;
          puVar2 = puVar2 + 2;
        } while (uVar8 < uVar3);
      }
      if (uVar8 == uVar3) {
        return 0xffffffff;
      }
    }
  }
  if (**(int **)(param_1 + 0x30) != 0) {
    uVar3 = thunk_FUN_00573310(param_3,0x4b0,&local_58,0x10);
    GetTextExtentPoint32W(DAT_00ddb2f0,(LPCWSTR)&local_58,uVar3 >> 1,&local_60);
    TextOutW(DAT_00ddb2f0,0,0,(LPCWSTR)&local_58,uVar3 >> 1);
    uVar3 = *(uint *)(*(int *)(param_1 + 0x30) + 0xc);
    pvBuffer = *(LPVOID *)(*(int *)(param_1 + 0x30) + 8);
    iVar9 = 0;
    local_38.gmptGlyphOrigin.x = 0;
    local_68 = 5;
    UVar7 = local_60.cx;
LAB_00596503:
    FUN_00531190(param_1,param_2,uVar1,0,local_68,pvBuffer,local_60.cx,local_60.cy,uVar3,
                 local_38.gmptGlyphOrigin.x,iVar9,UVar7,param_4);
    return 0;
  }
  local_58.eM11.fract = 0;
  local_58.eM11.value = 1;
  local_58.eM12.fract = 0;
  local_58.eM12.value = 0;
  local_58.eM21.fract = 0;
  local_58.eM21.value = 0;
  local_58.eM22.fract = 0;
  local_58.eM22.value = 1;
  switch(*(int *)(param_1 + 0x93184)) {
  case 0:
  case 1:
  case 0x12:
  case 0x13:
  case 0x22:
  case 0x23:
    local_6c = 1;
                    /* WARNING (jumptable): Sanity check requires truncation of jumptable */
                    /* WARNING: Could not find normalized switch variable to match jumptable */
    switch((&DAT_00596560)[*(int *)(param_1 + 0x93184)]) {
    case 0:
      local_68 = 0;
      break;
    case 1:
      local_68 = 1;
      break;
    case 2:
      local_68 = 2;
    }
    break;
  case 2:
  case 3:
    if ((*(int *)(param_1 + 0x93628) == 0) || (*(int *)(param_1 + 0x935fc) == 0x10)) {
      local_6c = 5;
      local_68 = 6;
    }
    else {
      local_6c = 6;
      local_68 = 7;
    }
  }
  if (0xffff < param_3) {
    FUN_0056d380(&local_24,0,0x24);
    local_24.lpGlyphs = (LPWSTR)&local_60;
    local_24.lStructSize = 0x24;
    local_24.nGlyphs = 2;
    iVar9 = thunk_FUN_00573310(param_3,0x4b0,local_48,0x10);
    DVar4 = GetCharacterPlacementW(DAT_00ddb2f0,local_48,iVar9 / 2,0,&local_24,0x10);
    if (DVar4 == 0) {
      FUN_0056bb10(&PTR_LAB_007d9ec0);
      return 0xffffffff;
    }
  }
  FUN_0056d380(&local_38,0,0x14);
  if (param_3 < 0x10000) {
    param_3 = GetGlyphOutlineW(DAT_00ddb2f0,param_3,local_6c,&local_38,0,(LPVOID)0x0,&local_58);
  }
  else {
    param_3 = GetGlyphOutlineW(DAT_00ddb2f0,(uint)(ushort)*(LONG *)local_24.lpGlyphs,local_6c | 0x80
                               ,&local_38,0,(LPVOID)0x0,&local_58);
  }
  if (param_3 != 0xffffffff) {
    if (bVar6 != 0) {
      FUN_00531190(param_1,param_2,uVar1,1,local_68,0,0,0,0,0,0,(int)local_38.gmCellIncX,0);
      return 0;
    }
    if (param_3 == 0) {
      FUN_00531190(param_1,param_2,uVar1,0,0,0,0,0,0,0,0,0,0);
      return 0;
    }
    uVar3 = param_3 / local_38.gmBlackBoxY & 0xfffffffc;
    uVar8 = (local_38.gmBlackBoxY + 2) * uVar3 + param_3;
    if (*(uint *)(*(int *)(param_1 + 0x30) + 0x1c) < uVar8) {
      *(uint *)(*(int *)(param_1 + 0x30) + 0x1c) = uVar8;
      if (*(int *)(*(int *)(param_1 + 0x30) + 0x18) != 0) {
        FUN_0056e1d0(*(undefined4 *)(*(int *)(param_1 + 0x30) + 0x18));
        *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x18) = 0;
      }
      uVar5 = FUN_0056e030(*(undefined4 *)(*(int *)(param_1 + 0x30) + 0x1c),
                           "..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxFontWin.cpp",0x2ff);
      *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x18) = uVar5;
      if (*(int *)(*(int *)(param_1 + 0x30) + 0x18) == 0) {
        FUN_0056bb10(&DAT_007d9e40);
        return 0xffffffff;
      }
    }
    FUN_0056d380(*(undefined4 *)(*(int *)(param_1 + 0x30) + 0x18),0,uVar8);
    pvBuffer = (LPVOID)((local_38.gmBlackBoxY + 1) * uVar3 +
                       *(int *)(*(int *)(param_1 + 0x30) + 0x18));
    if (uVar1 < 0x10000) {
      uVar3 = uVar1;
    }
    else {
      local_6c = local_6c | 0x80;
      uVar3 = (uint)(ushort)*(LONG *)local_24.lpGlyphs;
    }
    DVar4 = GetGlyphOutlineW(DAT_00ddb2f0,uVar3,local_6c,&local_38,param_3,pvBuffer,&local_58);
    if (DVar4 != 0xffffffff) {
      UVar7 = (UINT)local_38.gmCellIncX;
      iVar9 = DAT_00ddb300 - local_38.gmptGlyphOrigin.y;
      uVar3 = DVar4 / local_38.gmBlackBoxY & 0xfffffffc;
      local_60.cx = local_38.gmBlackBoxX;
      local_60.cy = local_38.gmBlackBoxY;
      goto LAB_00596503;
    }
  }
  FUN_0056bb10(&PTR_LAB_007d9e78);
  return 0xffffffff;
}

