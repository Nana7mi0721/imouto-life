
void FUN_006514d0(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar3 = *(uint *)(param_1 + 0x44);
  uVar2 = *(uint *)(param_1 + 0x48);
  uVar1 = *(uint *)(param_1 + 0x4c);
  if (uVar3 == 0xffffffff) {
    uVar3 = *(uint *)(param_1 + 0x38);
  }
  if (uVar2 == 0xffffffff) {
    uVar2 = *(uint *)(param_1 + 0x3c);
  }
  if (uVar1 == 0xffffffff) {
    uVar1 = *(uint *)(param_1 + 0x40);
  }
  if (((uVar3 == 0) || (uVar2 == 0)) || (uVar1 == 0)) {
    uVar4 = 0;
  }
  else {
    if (*(uint *)(param_1 + 0x40) < -uVar1) {
      uVar1 = ((*(uint *)(param_1 + 0x40) - 1) + uVar1) / uVar1;
    }
    else {
      uVar1 = 0;
    }
    if (*(uint *)(param_1 + 0x3c) < -uVar2) {
      uVar2 = ((*(uint *)(param_1 + 0x3c) - 1) + uVar2) / uVar2;
    }
    else {
      uVar2 = 0;
    }
    if (*(uint *)(param_1 + 0x38) < -uVar3) {
      uVar3 = ((*(uint *)(param_1 + 0x38) - 1) + uVar3) / uVar3;
    }
    else {
      uVar3 = 0;
    }
    uVar4 = FUN_00650ae0(param_1,uVar3,uVar2,s_TIFFNumberOfTiles_00a06c68,uVar1,
                         s_TIFFNumberOfTiles_00a06c68);
    uVar4 = FUN_00650ae0(param_1,uVar4);
  }
  if (*(short *)(param_1 + 0x7e) == 2) {
    FUN_00650ae0(param_1,uVar4,*(undefined2 *)(param_1 + 0x62),s_TIFFNumberOfTiles_00a06c68);
  }
  return;
}

