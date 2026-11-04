
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_005bdb20(int param_1,int param_2)

{
  int iVar1;
  float fVar2;
  uint uVar3;
  float10 fVar4;
  uint local_470;
  float local_46c;
  uint local_468;
  uint local_464;
  float local_460;
  float local_45c;
  float local_458;
  undefined4 local_454;
  int local_450;
  int local_44c;
  int local_448;
  int local_444;
  undefined1 local_440;
  byte local_43f;
  char local_43e;
  char local_43d;
  char local_43b;
  float *local_c;
  
  FUN_00568ca0(0);
  if (DAT_00dda46c != 0) {
    FUN_00584d70();
  }
  local_450 = param_1;
  local_448 = param_1 + 1;
  local_44c = param_2;
  local_444 = param_2 + 1;
  iVar1 = FUN_005229c0(&local_450,&local_440,0xffffffff,0xffffffff,0xffffffff,1,0);
  if (iVar1 < 0) {
    return 0xffffffff;
  }
  if (local_43d == '\0') {
    if (local_43b == '\x10') {
      fVar2 = (float)(uint)*(ushort *)local_c;
    }
    else {
      if (local_43b != ' ') goto LAB_005bde20;
      fVar2 = *local_c;
    }
    FUN_00544290(&local_440,fVar2,&local_470,&local_468,&local_464,&local_454);
    goto LAB_005bde20;
  }
  if (local_43e == '\x10') {
    fVar4 = (float10)FUN_00540830(*(undefined2 *)local_c);
    local_46c = (float)fVar4;
    if (local_43f < 2) {
      local_45c = 1.0;
    }
    else {
      fVar4 = (float10)FUN_00540830(*(undefined2 *)((int)local_c + 2));
      local_45c = (float)fVar4;
    }
    if (local_43f < 3) {
      local_460 = 1.0;
    }
    else {
      fVar4 = (float10)FUN_00540830(*(undefined2 *)(local_c + 1));
      local_460 = (float)fVar4;
    }
    if (local_43f < 4) {
LAB_005bdc6c:
      local_458 = 1.0;
    }
    else {
      fVar4 = (float10)FUN_00540830(*(undefined2 *)((int)local_c + 6));
      local_458 = (float)fVar4;
    }
  }
  else if (local_43e == ' ') {
    local_46c = *local_c;
    if (local_43f < 2) {
      local_45c = 1.0;
    }
    else {
      local_45c = local_c[1];
    }
    if (local_43f < 3) {
      local_460 = 1.0;
    }
    else {
      local_460 = local_c[2];
    }
    if (local_43f < 4) goto LAB_005bdc6c;
    local_458 = local_c[3];
  }
  if (NAN(local_46c) || local_46c < 0.0 == (local_46c == 0.0)) {
    if (local_46c < 1.0) {
      local_46c = local_46c * (float)_DAT_0081ec30;
      local_470 = FUN_0050e270(local_46c);
    }
    else {
      local_470 = 0xff;
    }
  }
  else {
    local_470 = 0;
  }
  if (NAN(local_45c) || local_45c < 0.0 == (local_45c == 0.0)) {
    if (local_45c < 1.0) {
      local_46c = local_45c * (float)_DAT_0081ec30;
      local_468 = FUN_0050e270(local_46c);
    }
    else {
      local_468 = 0xff;
    }
  }
  else {
    local_468 = 0;
  }
  if (NAN(local_460) || local_460 < 0.0 == (local_460 == 0.0)) {
    if (local_460 < 1.0) {
      local_46c = local_460 * (float)_DAT_0081ec30;
      local_464 = FUN_0050e270(local_46c);
    }
    else {
      local_464 = 0xff;
    }
  }
  else {
    local_464 = 0;
  }
  if (NAN(local_458) || local_458 < 0.0 == (local_458 == 0.0)) {
    if (1.0 <= local_458) {
      local_454 = 0xff;
    }
    else {
      local_46c = local_458 * (float)_DAT_0081ec30;
      local_454 = FUN_0050e270(local_46c);
    }
  }
  else {
    local_454 = 0;
  }
LAB_005bde20:
  uVar3 = ((local_470 | 0xffffff00) << 8 | local_468) << 8 | local_464;
  FUN_00517420();
  return uVar3;
}

