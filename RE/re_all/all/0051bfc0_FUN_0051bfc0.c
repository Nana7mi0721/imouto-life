
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0051bfc0(void)

{
  double dVar1;
  float10 fVar2;
  undefined8 uVar3;
  double dVar4;
  double dStack_88;
  double dStack_80;
  double dStack_78;
  double local_70;
  double local_68;
  double local_60;
  double local_58;
  double local_50;
  double local_48;
  
  local_70 = _DAT_00a38358;
  local_68 = _DAT_00a38378;
  local_60 = _DAT_00a38398;
  local_58 = _DAT_00a38368;
  local_50 = _DAT_00a38388;
  local_48 = _DAT_00a383a8;
  if ((((_DAT_007d54f8 <= _DAT_00a38368) || (_DAT_00a38368 <= _DAT_007d54f0)) ||
      (_DAT_007d54f8 <= _DAT_00a383a8)) || (_DAT_00a383a8 <= _DAT_007d54f0)) {
    if (0.0 <= _DAT_00a38380) {
      fVar2 = (float10)FUN_0056d520(_DAT_00a38368,_DAT_00a383a8);
      _DAT_00a3d2b0 = (double)fVar2;
      FUN_0056d4a0((double)-fVar2,&dStack_80,&dStack_88);
      dStack_78 = dStack_88 * local_60 - dStack_80 * local_70;
      local_70 = dStack_80 * local_60 + dStack_88 * local_70;
      fVar2 = (float10)FUN_0056d520(-local_50,dStack_88 * local_48 - dStack_80 * local_58);
      uVar3 = CONCAT44(&dStack_88,&dStack_80);
    }
    else {
      fVar2 = (float10)FUN_0056d520(-_DAT_00a38368,-_DAT_00a383a8);
      _DAT_00a3d2b0 = (double)fVar2;
      FUN_0056d4a0((double)-fVar2,&dStack_80,&dStack_88);
      dStack_78 = dStack_88 * local_60 - dStack_80 * local_70;
      local_70 = dStack_80 * local_60 + dStack_88 * local_70;
      dVar1 = dStack_88 * local_48 - dStack_80 * local_58;
      if (local_50 <= 0.0) {
        fVar2 = (float10)FUN_0056d520(-dVar1,-local_50);
        fVar2 = fVar2 + (float10)_DAT_007d54e8;
        uVar3 = CONCAT44(&dStack_88,&dStack_80);
      }
      else {
        fVar2 = (float10)FUN_0056d520(-dVar1,local_50);
        fVar2 = -fVar2 - (float10)_DAT_007d54e8;
        uVar3 = CONCAT44(&dStack_88,&dStack_80);
      }
    }
    _DAT_00a3d2b8 = (double)fVar2;
    FUN_0056d4a0((double)-fVar2,uVar3);
    dVar1 = dStack_88 * local_68 - dStack_78 * dStack_80;
    dVar4 = local_70;
  }
  else {
    _DAT_00a3d2b0 = 0.0;
    if (0.0 <= _DAT_00a38388) {
      _DAT_00a3d2b8 = _DAT_007d54e0;
      dVar4 = -_DAT_00a383a0;
      dVar1 = -_DAT_00a38360;
    }
    else {
      _DAT_00a3d2b8 = _DAT_007d54e8;
      dVar1 = -_DAT_00a38360;
      dVar4 = _DAT_00a383a0;
    }
  }
  fVar2 = (float10)FUN_0056d520(dVar1,dVar4);
  _DAT_00a3d2c0 = (double)fVar2;
  return;
}

