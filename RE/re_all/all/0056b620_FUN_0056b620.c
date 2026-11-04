
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0056b620(void)

{
  int iVar1;
  undefined4 local_918;
  undefined4 local_914;
  undefined4 local_910;
  undefined4 local_90c;
  undefined4 local_908;
  undefined4 local_904;
  undefined1 local_900 [256];
  undefined1 local_800 [2048];
  
  if ((DAT_00aaf110 == 0) && (DAT_00aaf118 != 1)) {
    if (DAT_00aaf120 == 0) {
      if (DAT_00aaff20 == 1) {
        FUN_00550150(&local_918);
        FUN_0056cf10(&DAT_00aaff24,&DAT_007d7884);
        FUN_0056d690(local_918,local_900,10);
        FUN_0056cfe0(&DAT_00aaff24,local_900);
        FUN_0056cfe0(&DAT_00aaff24,&DAT_007d7880);
        FUN_0056d690(local_914,local_900,10);
        FUN_0056cfe0(&DAT_00aaff24,local_900);
        FUN_0056cfe0(&DAT_00aaff24,&DAT_007d7880);
        FUN_0056d690(local_910,local_900,10);
        FUN_0056cfe0(&DAT_00aaff24,local_900);
        FUN_0056cfe0(&DAT_00aaff24,&DAT_007d7880);
        FUN_0056d690(local_90c,local_900,10);
        FUN_0056cfe0(&DAT_00aaff24,local_900);
        FUN_0056cfe0(&DAT_00aaff24,&DAT_007d7880);
        FUN_0056d690(local_908,local_900,10);
        FUN_0056cfe0(&DAT_00aaff24,local_900);
        FUN_0056cfe0(&DAT_00aaff24,&DAT_007d7880);
        FUN_0056d690(local_904,local_900,10);
        FUN_0056cfe0(&DAT_00aaff24,local_900);
        FUN_0056cfe0(&DAT_00aaff24,L".txt");
      }
      else {
        FUN_0056cf10(&DAT_00aaff24,L"Log.txt");
      }
    }
    else {
      FUN_0056cf70(&DAT_00aaff24,0x200,&DAT_00aaf120);
    }
    FUN_0056b590();
    iVar1 = FUN_005d6730(local_800);
    if (iVar1 < 0) {
      return 0xffffffff;
    }
    DAT_00ab0124 = 0;
    DAT_00ab0128 = 0;
    _DAT_00aaf11c = FUN_00550060(0);
    DAT_00aaf110 = 1;
  }
  return 0;
}

