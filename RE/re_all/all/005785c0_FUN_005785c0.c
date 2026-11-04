
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_005785c0(double param_1,int param_2,int param_3,char *param_4)

{
  double dVar1;
  double dVar2;
  bool bVar3;
  uint in_EAX;
  int iVar4;
  int iVar5;
  int iVar6;
  float10 fVar7;
  char local_48c;
  undefined1 *local_488;
  int local_484;
  undefined1 *local_480;
  double local_478;
  undefined1 local_460 [1116];
  
  local_480 = (undefined1 *)0x0;
  if (((int)in_EAX < 0) || (in_EAX < 0x400)) {
    local_488 = local_460;
LAB_0057861e:
    if ((int)in_EAX < 0) {
      in_EAX = 6;
    }
    else if (in_EAX == 0) {
      in_EAX = 1;
    }
  }
  else {
    local_488 = (undefined1 *)
                FUN_0056e030(in_EAX + 0x20,"..\\..\\..\\..\\Source\\Library\\Main\\DxChar.cpp",
                             0x1443);
    local_480 = local_488;
    if (local_488 != (undefined1 *)0x0) goto LAB_0057861e;
    in_EAX = 0x400;
    local_488 = local_460;
  }
  if (param_1 < 0.0) {
    param_1 = -param_1;
  }
  bVar3 = false;
  while( true ) {
    dVar2 = 1.0;
    iVar5 = 0;
    local_478 = 1.0;
    dVar1 = param_1;
    if (param_1 != 0.0) {
      if (1.0 <= param_1) {
        if (_DAT_0081ec08 <= param_1) {
          do {
            dVar1 = dVar1 / _DAT_0081ec08;
            iVar5 = iVar5 + 1;
            local_478 = dVar2 * _DAT_0081ec08;
            dVar2 = local_478;
          } while (_DAT_0081ec08 <= dVar1);
        }
      }
      else {
        do {
          dVar1 = dVar1 * _DAT_0081ec08;
          iVar5 = iVar5 + -1;
          local_478 = dVar2 / _DAT_0081ec08;
          dVar2 = local_478;
        } while (dVar1 < 1.0);
      }
    }
    local_484 = -1;
    FUN_006c57aa();
    iVar6 = 0;
    if (0 < (int)(in_EAX - 1)) {
      do {
        local_478 = local_478 / _DAT_0081ec08;
        fVar7 = (float10)FUN_006c57aa();
        local_48c = (char)(int)ROUND(fVar7);
        local_488[iVar6] = local_48c;
        if (local_488[iVar6] != '\0') {
          local_484 = iVar6;
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < (int)(in_EAX - 1));
    }
    if ((bVar3) || (fVar7 = (float10)FUN_006c57aa(), fVar7 <= (float10)_DAT_007d5558)) break;
    bVar3 = true;
    param_1 = local_478 + param_1;
  }
  if (iVar5 < 0) {
    if (iVar5 < -4) goto LAB_0057880c;
    iVar6 = (in_EAX - iVar5) + -1;
    if (param_2 == 0) {
      iVar5 = (local_484 - iVar5) + 1;
      if (iVar5 < iVar6) {
        iVar6 = iVar5;
      }
    }
  }
  else {
    if ((int)in_EAX <= iVar5) {
LAB_0057880c:
      iVar6 = 1;
      local_48c = (char)(int)ROUND(dVar1);
      *param_4 = local_48c + '0';
      if (param_2 == 0) {
        in_EAX = local_484 + 2;
      }
      if ((1 < (int)in_EAX) || (param_2 != 0)) {
        param_4[1] = '.';
        iVar6 = 2;
      }
      iVar4 = 0;
      if (0 < (int)(in_EAX - 1)) {
        do {
          param_4[iVar6] = local_488[iVar4] + '0';
          iVar4 = iVar4 + 1;
          iVar6 = iVar6 + 1;
        } while (iVar4 < (int)(in_EAX - 1));
      }
      param_4[iVar6] = (-(param_3 != 0) & 0xe0U) + 0x65;
      if (iVar5 < 0) {
        iVar5 = -iVar5;
        param_4[iVar6 + 1] = '-';
      }
      else {
        param_4[iVar6 + 1] = '+';
      }
      param_4[iVar6 + 2] = (char)((iVar5 / 100) % 10) + '0';
      param_4[iVar6 + 4] = (char)iVar5 + (char)(iVar5 / 10) * -10 + '0';
      param_4[iVar6 + 3] = (char)((iVar5 / 10) % 10) + '0';
      iVar6 = iVar6 + 5;
      goto LAB_005788fc;
    }
    if (param_2 == 0) {
      iVar6 = (local_484 - iVar5) + 1;
    }
    else {
      iVar6 = (in_EAX - iVar5) + -1;
    }
    if (iVar6 < 0) {
      iVar6 = 0;
    }
  }
  iVar6 = FUN_00578390(param_1,param_2,iVar6,param_4);
LAB_005788fc:
  if (local_480 != (undefined1 *)0x0) {
    FUN_0056e1d0(local_480);
  }
  return iVar6;
}

