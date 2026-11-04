
undefined4 FUN_0057c450(void)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  uint in_EAX;
  int iVar4;
  int iVar5;
  undefined4 local_8;
  
  local_8 = 0;
  if (DAT_00ca3cd8 == 0) {
    return 0xffffffff;
  }
  FUN_0056da60(&DAT_00cc6284,"..\\..\\..\\..\\Source\\Library\\Main\\DxNetwork.cpp",0x6e8);
  if (((((DAT_00cc6240 == 0) || ((int)in_EAX < 0)) || ((in_EAX & 0x7c000000) != DAT_00cc6268)) ||
      (((DAT_00cc6270 <= (int)(in_EAX & 0xffff) ||
        (piVar3 = *(int **)(DAT_00cc6244 + (in_EAX & 0xffff) * 4), piVar3 == (int *)0x0)) ||
       ((*piVar3 * 0x10000 != (in_EAX & 0x3ff0000) || ((piVar3[4] != 0 || (piVar3[0xc] != 0))))))))
     || (DAT_00ca3d0c == 1)) {
    FUN_0056dac0(&DAT_00cc6284);
    return 0xffffffff;
  }
  DAT_00ca3d0c = 1;
  FUN_0057bf50(0);
  if (piVar3[0xe] == 0) {
    FUN_0056bb10(&DAT_007d8458);
    local_8 = 0xffffffff;
  }
  else if (piVar3[0x10] == 1) {
    FUN_0056bb10(&DAT_007d8400);
    local_8 = 0xffffffff;
  }
  else if (piVar3[0x16] == 1) {
    piVar1 = piVar3 + 0x19;
    do {
      if (*piVar1 == 0) {
        iVar4 = (*DAT_00aba120)(piVar3[0x18],piVar1,4,2);
        if (((iVar4 < 0) || (iVar4 < 4)) ||
           (iVar4 = (*DAT_00aba120)(piVar3[0x18],piVar1,4,0), iVar4 < 4)) break;
        piVar3[0x1f] = *piVar1;
        iVar4 = FUN_00597490(piVar3 + 0x1a,*piVar1);
        if (iVar4 < 0) {
          FUN_0056bca0(&DAT_007d83a0,*piVar1);
          piVar3[0x10] = 1;
          local_8 = 0xffffffff;
          break;
        }
      }
      piVar2 = piVar3 + 0x1a;
      FUN_0057beb0(piVar2);
      iVar4 = piVar3[0x1c];
      if (piVar3[0x1e] < iVar4 + *piVar1) {
        iVar4 = (*DAT_00aba120)(piVar3[0x18],*piVar2 + iVar4,piVar3[0x1e] - iVar4);
        if (iVar4 < 0) break;
        if (iVar4 < piVar3[0x1e] - piVar3[0x1c]) {
          piVar3[0x1c] = piVar3[0x1c] + iVar4;
        }
        else {
          iVar5 = (*DAT_00aba120)(piVar3[0x18],*piVar2,*piVar1 - iVar4,0);
          if (iVar5 < 0) {
            piVar3[0x1c] = 0;
          }
          else {
            piVar3[0x1c] = iVar5;
            iVar4 = iVar5 + iVar4;
          }
        }
      }
      else {
        iVar4 = (*DAT_00aba120)(piVar3[0x18],*piVar2 + iVar4,*piVar1,0);
        if (iVar4 < 0) break;
        piVar3[0x1c] = piVar3[0x1c] + iVar4;
      }
      piVar3[0x1d] = piVar3[0x1d] + iVar4;
      *piVar1 = *piVar1 - iVar4;
      if (*piVar1 == 0) {
        piVar3[0x20] = piVar3[0x20] + piVar3[0x1f];
      }
      iVar5 = FUN_0057bf50(0);
      if (((iVar5 != 0) || (iVar4 < 1)) || (*piVar1 != 0)) break;
    } while( true );
  }
  DAT_00ca3d0c = 0;
  FUN_0056dac0(&DAT_00cc6284);
  return local_8;
}

