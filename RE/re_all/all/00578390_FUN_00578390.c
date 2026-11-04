
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00578390(double param_1,int param_2,uint param_3,undefined1 *param_4)

{
  double dVar1;
  bool bVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float10 fVar7;
  undefined1 local_44c;
  double local_440;
  undefined1 *local_434;
  double local_430;
  undefined1 local_428 [1060];
  
  local_434 = (undefined1 *)0x0;
  if ((int)param_3 < 0) {
    param_3 = 6;
  }
  else if (0x3ff < param_3) {
    puVar3 = (undefined1 *)
             FUN_0056e030(param_3 + 0x20,"..\\..\\..\\..\\Source\\Library\\Main\\DxChar.cpp",0x13b6)
    ;
    local_434 = puVar3;
    if (puVar3 != (undefined1 *)0x0) goto LAB_005783b7;
    param_3 = 0x400;
  }
  puVar3 = local_428;
LAB_005783b7:
  if (param_1 < 0.0) {
    param_1 = -param_1;
  }
  bVar2 = false;
  while( true ) {
    iVar6 = 0;
    fVar7 = (float10)FUN_006c57aa();
    dVar1 = _DAT_0081ec08;
    local_430 = (double)((float10)param_1 - fVar7);
    iVar4 = 0;
    if ((float10)1 <= (float10)param_1) {
      do {
        iVar5 = iVar4;
        fVar7 = (float10)FUN_006c57aa();
        dVar1 = _DAT_0081ec08;
        local_44c = (undefined1)(int)ROUND(fVar7);
        puVar3[iVar5] = local_44c;
        local_430 = (local_430 - (double)((int)ROUND(fVar7) & 0xff)) / _DAT_0081ec08;
        iVar4 = iVar5 + 1;
      } while (!NAN(local_430) && 1.0 < local_430 != (local_430 == 1.0));
      for (; -1 < iVar5; iVar5 = iVar5 + -1) {
        param_4[iVar6] = puVar3[iVar5] + '0';
        iVar6 = iVar6 + 1;
      }
    }
    else {
      *param_4 = 0x30;
      iVar6 = 1;
    }
    iVar5 = 0;
    local_440 = 1.0;
    iVar4 = iVar5;
    if (0 < (int)param_3) {
      do {
        local_440 = local_440 / dVar1;
        fVar7 = (float10)FUN_006c57aa();
        iVar5 = iVar4 + 1;
        local_44c = (undefined1)(int)ROUND(fVar7);
        puVar3[iVar4] = local_44c;
        iVar4 = iVar5;
        dVar1 = _DAT_0081ec08;
      } while (iVar5 < (int)param_3);
    }
    if ((bVar2) || (fVar7 = (float10)FUN_006c57aa(), fVar7 <= (float10)_DAT_007d5558)) break;
    bVar2 = true;
    param_1 = local_440 + param_1;
  }
  if ((param_3 != 0) || (param_2 != 0)) {
    param_4[iVar6] = 0x2e;
    iVar6 = iVar6 + 1;
    iVar4 = 0;
    if (0 < iVar5) {
      do {
        param_4[iVar6] = puVar3[iVar4] + '0';
        iVar4 = iVar4 + 1;
        iVar6 = iVar6 + 1;
      } while (iVar4 < iVar5);
    }
  }
  if (local_434 != (undefined1 *)0x0) {
    FUN_0056e1d0(local_434);
  }
  return iVar6;
}

