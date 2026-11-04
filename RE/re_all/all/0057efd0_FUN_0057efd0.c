
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0057efd0(int param_1)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  float *pfVar5;
  float10 fVar6;
  int *local_49c;
  float *local_498;
  undefined1 *local_494;
  float local_484;
  int *local_480;
  float fStack_47c;
  float local_478;
  float local_474;
  float local_470;
  int *local_468;
  float local_464;
  float local_460;
  undefined1 auStack_454 [4];
  undefined4 uStack_450;
  float fStack_44c;
  undefined4 uStack_448;
  float fStack_444;
  float fStack_440;
  undefined4 uStack_43c;
  int *local_438 [2];
  uint local_430;
  float local_42c [4];
  undefined4 uStack_41c;
  undefined1 auStack_414 [12];
  int local_408 [257];
  
  if (DAT_00aa4fa0 == 0) {
    local_49c = (int *)(*(float *)(param_1 + 0x74) - _DAT_00a83504);
    local_498 = (float *)(*(float *)(param_1 + 0x78) - _DAT_00a83508);
    local_494 = (undefined1 *)(*(float *)(param_1 + 0x7c) - _DAT_00a8350c);
    local_468 = local_49c;
    local_464 = (float)local_498;
    local_460 = (float)local_494;
    fVar6 = (float10)FUN_005863d0();
    local_470 = (float)fVar6;
    if ((float)fVar6 < (float)_DAT_007d97b8) {
      local_470 = _DAT_007d97b0;
    }
    if (local_470 <= *(float *)(param_1 + 0xb4)) {
      local_480 = (int *)(1.0 - local_470 / *(float *)(param_1 + 0xb4));
    }
    else {
      local_480 = (int *)0x0;
    }
    local_470 = 1.0 / local_470;
    local_478 = local_470 * (float)local_468;
    local_474 = local_464 * local_470;
    local_470 = local_470 * local_460;
    local_494 = (undefined1 *)
                (_DAT_00a83518 * local_470 + local_478 * _DAT_00a83510 + _DAT_00a83514 * local_474);
    local_498 = (float *)0x57f352;
    fVar6 = (float10)FUN_0056d550();
    fVar1 = (float)(fVar6 + fVar6);
    if (_DAT_00a83534 <= fVar1) {
      if (fVar1 <= _DAT_00a83538) {
        fVar1 = (_DAT_00a83540 - _DAT_00a8353c) *
                ((fVar1 - _DAT_00a83534) / (_DAT_00a83538 - _DAT_00a83534)) + _DAT_00a8353c;
      }
      else {
        fVar1 = _DAT_00a83540;
      }
    }
    else {
      fVar1 = _DAT_00a8353c;
    }
    local_480 = (int *)(fVar1 * (float)local_480);
    local_478 = _DAT_00a8354c * local_470 + _DAT_00a83544 * local_478 + _DAT_00a83548 * local_474;
    if (0.0 <= local_478) {
      local_484 = local_478;
    }
    else {
      local_484 = -local_478;
    }
    if ((float)_DAT_007d97a8 < local_484) {
      local_484 = _DAT_007d5914;
    }
    if (local_478 < 0.0) {
      local_484 = -local_484;
    }
    local_494 = (undefined1 *)param_1;
    *(int **)(param_1 + 0xc0) = local_480;
    *(float *)(param_1 + 0xc4) = local_484;
    local_498 = (float *)0x57f456;
    FUN_00551a70();
    return 0;
  }
  uVar4 = 0x3d;
  if (((byte)DAT_00aa4f2c & 8) != 0) {
    uVar4 = 0x2003d;
  }
  local_494 = (undefined1 *)0x400;
  local_49c = local_408;
  local_498 = (float *)0x0;
  FUN_0056d380();
  FUN_0056d380(local_438,0,0x30);
  local_430 = (uint)*(ushort *)(param_1 + 0x32);
  local_42c[0] = DAT_00a834f4;
  local_438[0] = local_408;
  (*DAT_00aa426c)(&DAT_00aa4f30,&DAT_00aa4f64,param_1 + 0x114,uVar4,local_438);
  local_494 = auStack_454;
  local_49c = (int *)(local_42c[1] * (float)_DAT_007d97c0);
  local_498 = &fStack_47c;
  local_480 = local_49c;
  FUN_0056d4d0();
  fStack_440 = fStack_47c + fStack_47c;
  local_494 = auStack_454;
  local_498 = &fStack_47c;
  uStack_43c = 0x3f800000;
  fStack_444 = 0.0;
  local_49c = (int *)(local_42c[2] * (float)_DAT_007d97c0);
  local_480 = local_49c;
  FUN_0056d4d0();
  local_49c = *(int **)(param_1 + 200);
  fStack_44c = fStack_47c + fStack_47c;
  uStack_450 = 0;
  local_494 = (undefined1 *)0x0;
  uStack_448 = 0x3f800000;
  if (DAT_00aa4254 == 0) {
    local_498 = (float *)uStack_41c;
    (**(code **)(*local_49c + 0x68))();
    (**(code **)(**(int **)(param_1 + 200) + 0x40))
              (*(int **)(param_1 + 200),DAT_00aa4f1c,*(undefined2 *)(param_1 + 0x32),DAT_00a834f4,
               auStack_414,0);
    uVar3 = (uint)*(ushort *)(param_1 + 0x32);
    iVar2 = uVar3 * uVar3;
    if (0 < iVar2) {
      pfVar5 = local_42c;
      for (; iVar2 != 0; iVar2 = iVar2 + -1) {
        *pfVar5 = fStack_444;
        pfVar5 = pfVar5 + 1;
      }
    }
    (**(code **)(**(int **)(param_1 + 200) + 0x40))
              (*(int **)(param_1 + 200),*(undefined4 *)(param_1 + 0xcc),uVar3,uVar3,local_42c,0);
    (**(code **)(**(int **)(param_1 + 200) + 0x28))
              (*(int **)(param_1 + 200),DAT_00aa4f1c,&local_480,0);
    (**(code **)(**(int **)(param_1 + 200) + 0x28))
              (*(int **)(param_1 + 200),*(undefined4 *)(param_1 + 0xcc),&local_49c,0);
    return 0;
  }
  local_498 = (float *)uStack_41c;
  (**(code **)(*local_49c + 0x68))();
  (**(code **)(**(int **)(param_1 + 200) + 0x40))
            (*(int **)(param_1 + 200),DAT_00aa4f20,*(undefined2 *)(param_1 + 0x32),DAT_00a834f4,
             auStack_414,0);
  uVar3 = (uint)*(ushort *)(param_1 + 0x32);
  iVar2 = uVar3 * uVar3;
  if (0 < iVar2) {
    pfVar5 = local_42c;
    for (; iVar2 != 0; iVar2 = iVar2 + -1) {
      *pfVar5 = fStack_444;
      pfVar5 = pfVar5 + 1;
    }
  }
  (**(code **)(**(int **)(param_1 + 200) + 0x40))
            (*(int **)(param_1 + 200),*(undefined4 *)(param_1 + 0xcc),uVar3,uVar3,local_42c,0);
  (**(code **)(**(int **)(param_1 + 200) + 0x28))
            (*(int **)(param_1 + 200),DAT_00aa4f20,&local_480,0);
  (**(code **)(**(int **)(param_1 + 200) + 0x28))
            (*(int **)(param_1 + 200),*(undefined4 *)(param_1 + 0xcc),&local_49c,0);
  return 0;
}

