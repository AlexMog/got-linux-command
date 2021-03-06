#define _GNU_SOURCE
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "got.h"

static t_quote got_quotes[] = {
  {"Ygritte", "You know nothing, Jon Snow."},
  {"Jaime Lannister", "Give my regards to the Night’s Watch. I’m sure it will be thrilling. And if it’s not, it’s only for life."},
  {"Eddard ‘Ned’ Stark", "War was easier than daughters."},
  {"Daenerys Targaryen", "I am a Khaleesi of the Dothraki. I am the wife of the great Kahl and I carry his son inside me. The next time you raise a hand to me will be the last time you have hands."},
  {"Tyrion Lannister", "A Lannister always pays his debts."},
  {"Eddard ‘Ned’ Stark", "The man who passes the sentence should swing the sword."},
  {"Tonny Stark", "I'm a Stark!"},
  {"Cersei Lannister", "When you play the game of thrones, you win or you die."},
  {"Tyrion Lannister", "I will hurt you for this. A day will come when you think you are safe and happy, and your joy will turn to ashes in your mouth. And you will know the debt is paid."},
  {"Daenerys Targaryen", "A dragon is not a slave."},
  {"Tyrion Lannister", "And now I’ve struck a king. Did my hand fall from my wrist?"},
  {"Catelyn Stark", "Wise men do not make demands of kings."},
  {"Margaery Tyrell", "I want to be THE queen."},
  {"Cersei Lannister", "If you ever call me sister again I’ll have you strangled in your sleep."},
  {"Tywin Lannister", "Any man who must say, I am the king, is no true king."},
  {"Almost everyone", "Winter is comming..."},
  {"Jon Snow to Samwell Tarly", "The first Lord Commander in history to sacrifice the lives of sworn brothers to save the lives of wildlings. How’s it feel to be friends with the most hated man at Castle Black?"},
  {"Samwell Tarly", "The last thing I’ll see in this world will be the look in her eyes when I failed then"},
  {"Jon Snow", "I’m glad the end of the world’s working out well for someone."},
  {"Stannis Baratheon", "Go and do your duty."},
  {"Sansa Stark", "I know what Ramsay is. I know what he’ll do to me. If I’m going to die, let it happen while there’s still some of me left."},
  {"Arya Stark", "You know who I am. I’m Arya Stark. Do you know who you are? You’re no one. You’re nothing."},
  {"Jamie Lannister", "I’m glad Trystane’s coming with us, he seems like a nice boy. You’re lucky. Arranged marriages are rarely so well arranged."},
  {"Jamie Lannister", "We don’t choose whom we love. It just, well, it’s behind out control."},
  {"Tyrion Lannister", "You love her, don’t you? How could you not? Of course it’s hopeless for the both of you, a sellsword from the fighting pits and a disgraced knight. Neither one of you is fit consort for a queen, but we always want the wrong woman."},
  {"Tyrion Lannister", "My Valyrian is a bit nostril."},
  {"Jorah to Tyrion", "If I ever kill you, your eyes will be wide open."},
  {"Daario about Grey Worm", "He’s the toughest man with no balls I ever met."},
  {"Varys", "Information is the key. You need to learn your enemies’ strengths and strategies. You need to learn which of your friends are not your friends."},
  {"Qyburn to Cersei Lannister about the newest member of the Kingsguard", "He has taken a holy vow of silence. He’s sworn that he will not speak until all his grace’s enemies are dead and the evil has been driven from the realm."},
  {"Alliser Thorne and others to Jon while stabbing him", "For the Watch."},
  {"The Hound", "I'd skin you alive for wine."},
  {"Cersei Lannister", "I don't choose Tywin Lannister. I don't love Tywin Lannister. I love my brother. I love my lover."},
  {"Mance", "Stand down. I said my people have bled enough and I meant it."},
  {"Sam", "I made a promise to defend the wall and I have to keep it. That's what men do."},
  {"Aemon", "Nothing makes the past a sweeter place to visit than the prospect of imminent death."},
  {"Aemon", "Love is the death of duty."},
  {"Jon Snow", "For a little while, you're more than just you."},
  {"Tyrion Lannister", "Turns out, far too much has been written about great men and not nearly enough about morons. Doesn't seem right."},
  {"Dany", "Don't ever presume to touch me or speak my name again."},
  {"Ramsay", "Remember what you are and what you are not."},
  {"Grey Worm", "I remember nothing, only Unsullied."},
  {"Baelish", "Given the opportunity what do we do to those who've hurt the ones we love?"},
  {"Arya Stark", "Nothing isn't better or worse than anything. Nothing is just nothing."},
  {"Tyrion Lannister to Jamie Lannister", "You're the golden son. You can kill a king, lose a hand, fuck your own sister, you'll always be the golden son."},
  {"Jamie Lannister to Tyrion Lannister", "Careful, I'm the last friend you've got."},
  {"Tyrion Lannister", "Watching your vicious bastard die gave me more relief that a thousand lying whores."},
  {"Oberyn", "Tis a big and beautiful world. Most of us live and die in the same corner where we were born and never get to see any of it. I don't want to be most of us."},
  {"Davos", "He doesn't just talk about paying people back, he does it."},
  {"Tycho Nestoris", "Across the Narrow Sea, your books are filled with words like usurper and madmen and blood right. Here our books are filled with numbers. We prefer the stories they tell. More plain, less open to interpretation."},
  {"Cersei Lannister", "What good is power if you cannot protect the ones you love?"},
  {"Daenerys Targaryen", "I will not let those I have freed slide back into chains."},
  {"Cersei Lannister", "He could be the first man who sits on that throne in fifty years to actually deserve it."},
  {"Cersei Lannister", "You never love anything in the world the way you love your first child. It doesn't matter what they do. And what he did, it shocked me. Do you think I'm easily shocked?"},
  {"Baelish", "A man with no motive is a man no one suspects. Always keep your foes confused."},
  {"Tyrion Lannister", "Sansa's not a killer. Not yet anyway."},
  {"Shireen", "You won't be a very good hand if you see the word knight and say \"ka-niggit.\""},
  {"Daario Naharis", "Let me kill this man for you."},
  {"Oberyn", "When it comes to war I fight for Dorne. When it comes to love, I don't choose sides."},
  {"Stannis", "I will not become a page in someone else's history book."},
  {"Cersei Lannister", "Please Jaime you have to. He was our son, our baby boy."},
  {"Olenna Tyrell", "The world is overflowing with horrible things, but they're all a tray of cakes next to death."},
  {"Baelish", "Money buys a man's silence for a time. A bolt in the heart buys it forever."},
  {"Olenna Tyrell", "War is war, but killing a man at a wedding, horrid. What sort of monster would do such a thing? As if men need more reasons to fear marriage."},
  {"Bronn", "She's gone, I know you don't want to believe it, but she is. Now, go drink until it feels like you did the right thing."},
  {"Tyrion Lannister", "It's only wine."},
  {"Tyrion Lannister", "You lost a hand, not a stomach."},
  {"Tyrion Lannister", "I didn't know your brother. He seemed like a good man, but I didn't know him. Your mother on the other hand, I admired her. She wanted to have me executed, but I admired her."},
  {"Tywin", "A one handed man with no family needs all the help he can get."},
  {"Hodor", "Hodor!"}
};

t_quote* get_normal_quote(int *size, int *selected)
{
  *size = (int)(sizeof(got_quotes) / sizeof(got_quotes[0]));
  *selected = get_random(0, *size);
  return &got_quotes[*selected];
}

t_quote** construct_table(char *character, int *lsize)
{
  int		size, i, listsize;
  t_quote**	list;

  size = (int)(sizeof(got_quotes) / sizeof(got_quotes[0]));
  list = NULL;
  listsize = 0;
  for (i = 0; i < size; ++i)
    if (strcasestr(got_quotes[i].author, character) != NULL)
      {
	if ((list = realloc(list, (listsize + 1) * sizeof(list))) == NULL)
	  {
	    if (list != NULL)
	      free(list);
	    return (NULL);
	  }
	list[listsize] = &got_quotes[i];
	++listsize;
      }
  *lsize = listsize;
  return list;
}

t_quote* get_character_quote(t_options *options, int *size, int *selected)
{
  t_quote** list;
  t_quote* quote;

  list = construct_table(options->character, size);
  if (list == NULL)
    return (NULL);
  *selected = get_random(0, *size);
  quote = list[*selected];
  free(list);
  return quote;
}
