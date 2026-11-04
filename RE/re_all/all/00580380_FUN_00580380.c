
void FUN_00580380(undefined *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined *puVar5;
  int local_4;
  
  local_4 = 0;
  puVar5 = &DAT_00ca3d2c;
  iVar2 = 0;
  do {
    if (puVar5 == param_1) break;
    iVar2 = iVar2 + 1;
    puVar5 = puVar5 + 0x28;
  } while (iVar2 < 0x20);
joined_r0x005803ac:
  do {
    if (DAT_00ca3d20 == 1) {
      FUN_0056da60(&DAT_00ca4230,"..\\..\\..\\..\\Source\\Library\\Main\\DxASyncLoad.cpp",0x2ed);
      *(undefined4 *)(puVar5 + 0x10) = 1;
      DAT_00ca422c = DAT_00ca422c + -1;
      FUN_0056dac0();
      return;
    }
    if (DAT_00cc44d8 != 0) {
      FUN_0056da60(&DAT_00ca4230,"..\\..\\..\\..\\Source\\Library\\Main\\DxASyncLoad.cpp",0x2b1);
      iVar2 = 0;
      iVar3 = 0;
      if (0 < DAT_00cc44d8) {
        do {
          iVar1 = (&DAT_00ca44d4)[iVar3];
          if (((iVar1 != 0) && (*(int *)(iVar1 + 4) == 0)) &&
             ((iVar2 == 0 || (*(int *)(iVar1 + 8) <= *(int *)(iVar2 + 8))))) {
            iVar2 = iVar1;
            local_4 = iVar3;
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < DAT_00cc44d8);
        if (iVar2 != 0) {
          *(undefined4 *)(iVar2 + 4) = 1;
          *(undefined4 *)(puVar5 + 0x14) = 1;
          *(int *)(puVar5 + 0x24) = iVar2;
          FUN_0056dac0(&DAT_00ca4230);
          (**(code **)(iVar2 + 0xc))(iVar2);
          FUN_0056da60(&DAT_00ca4230,"..\\..\\..\\..\\Source\\Library\\Main\\DxASyncLoad.cpp",0x2dc)
          ;
          FUN_0057fc10(local_4,0);
          *(undefined4 *)(puVar5 + 0x14) = 0;
          *(undefined4 *)(puVar5 + 0x24) = 0;
          FUN_0056dac0(&DAT_00ca4230);
          goto joined_r0x005803ac;
        }
      }
      FUN_0056dac0(&DAT_00ca4230);
      FUN_0057fd00(1);
    }
    FUN_0056da60(&DAT_00ca4230,"..\\..\\..\\..\\Source\\Library\\Main\\DxASyncLoad.cpp",0x29d);
    *(undefined4 *)(puVar5 + 0x1c) = 1;
    uVar4 = FUN_00550060(0);
    *(undefined4 *)(puVar5 + 0x20) = uVar4;
    DAT_00ca422c = DAT_00ca422c + -1;
    FUN_0056dac0(&DAT_00ca4230);
    FUN_0056d9f0(param_1);
  } while( true );
}

