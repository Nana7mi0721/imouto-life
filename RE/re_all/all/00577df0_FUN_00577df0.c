
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00577df0(double param_1,int param_2,int param_3,undefined1 *param_4)

{
  double dVar1;
  double dVar2;
  bool bVar3;
  double dVar4;
  double dVar5;
  uint in_EAX;
  undefined1 *puVar6;
  int iVar7;
  int iVar8;
  float10 fVar9;
  char local_450;
  int local_44c;
  int local_448;
  undefined1 *local_444;
  double local_440;
  undefined1 local_428 [1060];
  
  local_444 = (undefined1 *)0x0;
  if (((int)in_EAX < 0) || (in_EAX < 0x400)) {
    puVar6 = local_428;
  }
  else {
    puVar6 = (undefined1 *)
             FUN_0056e030(in_EAX + 0x20,"..\\..\\..\\..\\Source\\Library\\Main\\DxChar.cpp",0x1262);
    local_444 = puVar6;
    if (puVar6 == (undefined1 *)0x0) {
      in_EAX = 0x400;
      puVar6 = local_428;
      goto LAB_00577e4d;
    }
  }
  if ((int)in_EAX < 0) {
    in_EAX = 6;
  }
LAB_00577e4d:
  if (param_1 < 0.0) {
    param_1 = -param_1;
  }
  bVar3 = false;
  local_448 = 3;
  while( true ) {
    dVar5 = _DAT_00829868;
    dVar4 = _DAT_00804a60;
    *param_4 = 0x30;
    param_4[1] = 0x78;
    local_440 = 1.0;
    dVar1 = param_1;
    if (param_1 == 0.0) {
      local_44c = 0;
    }
    else if (1.0 <= param_1) {
      local_44c = 0;
      dVar2 = 1.0;
      if (dVar5 <= param_1) {
        do {
          local_44c = local_44c + 1;
          dVar1 = dVar1 * dVar4;
          local_440 = dVar2 * dVar5;
          dVar2 = local_440;
        } while (dVar5 <= dVar1);
      }
    }
    else {
      local_44c = 0;
      local_440 = 1.0;
      do {
        dVar1 = dVar1 * dVar5;
        local_44c = local_44c + -1;
        local_440 = local_440 * dVar4;
      } while (dVar1 < 1.0);
    }
    local_450 = (char)(int)ROUND(dVar1);
    param_4[2] = local_450 + '0';
    FUN_006c57aa();
    iVar7 = 0;
    if (0 < (int)in_EAX) {
      do {
        local_440 = local_440 * _DAT_007d8138;
        fVar9 = (float10)FUN_006c57aa();
        iVar8 = iVar7 + 1;
        local_450 = (char)(int)ROUND(fVar9);
        puVar6[iVar7] = local_450;
        iVar7 = iVar8;
      } while (iVar8 < (int)in_EAX);
    }
    if ((bVar3) || (fVar9 = (float10)FUN_006c57aa(), fVar9 <= (float10)_DAT_0081ef70)) break;
    bVar3 = true;
    param_1 = local_440 + param_1;
  }
  if ((0 < (int)in_EAX) || (param_2 != 0)) {
    param_4[3] = 0x2e;
    local_448 = 4;
  }
  iVar7 = 0;
  if (0 < (int)in_EAX) {
    do {
      param_4[local_448] =
           s__Vf<q10123456789abcdef0123456789_0085e41a[param_3 * 0x10 + (byte)puVar6[iVar7] + 6];
      iVar7 = iVar7 + 1;
      local_448 = local_448 + 1;
    } while (iVar7 < (int)in_EAX);
  }
  param_4[local_448] = (-(param_3 != 0) & 0xe0U) + 0x70;
  if (local_44c < 0) {
    local_44c = -local_44c;
    param_4[local_448 + 1] = 0x2d;
  }
  else {
    param_4[local_448 + 1] = 0x2b;
  }
  local_448 = local_448 + 2;
  if (local_44c == 0) {
    iVar7 = 1;
    *puVar6 = 0;
  }
  else {
    iVar7 = 0;
    do {
      iVar8 = local_44c / 10;
      puVar6[iVar7] = (char)local_44c + (char)iVar8 * -10;
      iVar7 = iVar7 + 1;
      local_44c = iVar8;
    } while (iVar8 != 0);
  }
  iVar7 = iVar7 + -1;
  if (-1 < iVar7) {
    do {
      param_4[local_448] = puVar6[iVar7] + '0';
      local_448 = local_448 + 1;
      iVar7 = iVar7 + -1;
    } while (-1 < iVar7);
  }
  if (local_444 == (undefined1 *)0x0) {
    return local_448;
  }
  FUN_0056e1d0(local_444);
  return local_448;
}

