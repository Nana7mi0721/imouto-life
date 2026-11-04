
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_005780e0(double param_1,int param_2,int param_3,char *param_4)

{
  double dVar1;
  double dVar2;
  bool bVar3;
  uint in_EAX;
  int iVar4;
  int iVar5;
  int iVar6;
  float10 fVar7;
  char local_450;
  undefined1 *local_44c;
  double local_448;
  undefined1 *local_440;
  undefined1 local_428 [1060];
  
  local_440 = (undefined1 *)0x0;
  if (((int)in_EAX < 0) || (in_EAX < 0x400)) {
    local_44c = local_428;
  }
  else {
    local_44c = (undefined1 *)
                FUN_0056e030(in_EAX + 0x20,"..\\..\\..\\..\\Source\\Library\\Main\\DxChar.cpp",
                             0x1315);
    local_440 = local_44c;
    if (local_44c == (undefined1 *)0x0) {
      in_EAX = 0x400;
      local_44c = local_428;
      goto LAB_00578147;
    }
  }
  if ((int)in_EAX < 0) {
    in_EAX = 6;
  }
LAB_00578147:
  if (param_1 < 0.0) {
    param_1 = -param_1;
  }
  bVar3 = false;
  while( true ) {
    dVar2 = 1.0;
    iVar4 = 0;
    local_448 = 1.0;
    dVar1 = param_1;
    if (param_1 != 0.0) {
      if (1.0 <= param_1) {
        if (_DAT_0081ec08 <= param_1) {
          do {
            dVar1 = dVar1 / _DAT_0081ec08;
            iVar4 = iVar4 + 1;
            local_448 = dVar2 * _DAT_0081ec08;
            dVar2 = local_448;
          } while (_DAT_0081ec08 <= dVar1);
        }
      }
      else {
        do {
          dVar1 = dVar1 * _DAT_0081ec08;
          iVar4 = iVar4 + -1;
          local_448 = dVar2 / _DAT_0081ec08;
          dVar2 = local_448;
        } while (dVar1 < 1.0);
      }
    }
    FUN_006c57aa();
    iVar6 = 0;
    if (0 < (int)in_EAX) {
      do {
        local_448 = local_448 / _DAT_0081ec08;
        fVar7 = (float10)FUN_006c57aa();
        iVar5 = iVar6 + 1;
        local_450 = (char)(int)ROUND(fVar7);
        local_44c[iVar6] = local_450;
        iVar6 = iVar5;
      } while (iVar5 < (int)in_EAX);
    }
    if ((bVar3) || (fVar7 = (float10)FUN_006c57aa(), fVar7 <= (float10)_DAT_007d5558)) break;
    bVar3 = true;
    param_1 = local_448 + param_1;
  }
  iVar6 = 1;
  local_450 = (char)(int)ROUND(dVar1);
  *param_4 = local_450 + '0';
  if ((0 < (int)in_EAX) || (param_2 != 0)) {
    param_4[1] = '.';
    iVar6 = 2;
  }
  iVar5 = 0;
  if (0 < (int)in_EAX) {
    do {
      param_4[iVar6] = local_44c[iVar5] + '0';
      iVar5 = iVar5 + 1;
      iVar6 = iVar6 + 1;
    } while (iVar5 < (int)in_EAX);
  }
  param_4[iVar6] = (-(param_3 != 0) & 0xe0U) + 0x65;
  if (iVar4 < 0) {
    iVar4 = -iVar4;
    param_4[iVar6 + 1] = '-';
  }
  else {
    param_4[iVar6 + 1] = '+';
  }
  param_4[iVar6 + 2] = (char)((iVar4 / 100) % 10) + '0';
  param_4[iVar6 + 4] = (char)iVar4 + (char)(iVar4 / 10) * -10 + '0';
  param_4[iVar6 + 3] = (char)((iVar4 / 10) % 10) + '0';
  if (local_440 != (undefined1 *)0x0) {
    FUN_0056e1d0(local_440);
  }
  return iVar6 + 5;
}

